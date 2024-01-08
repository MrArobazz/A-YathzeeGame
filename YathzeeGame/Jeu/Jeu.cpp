//
// Created by macine on 04/01/24.
//

#include "Jeu.h"

using namespace std;

Jeu::Jeu() {

    unsigned int nb_joueurs = 0;
    unsigned int mode = 0 ;
    do {
        cout << "A combien souhaitez-vous jouer ?" << endl;
        cin >> nb_joueurs;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Saisie invalide :  Nombre Joueur invalide" << endl;
            continue;
        }
        if (nb_joueurs > 8) {
            cout << "Trop de joueurs. La limite est de 8." << endl;
            nb_joueurs = 0;
        };

    } while (nb_joueurs == 0) ;



    do {
        cout << "Choisir un Mode de Jeu"<<endl;
        cout << "1 : mode Facile"<<endl;
        cout << "2 : mode Normal"<<endl;
        cout << "3 : mode Difficile"<<endl;
        cout << "4 : mode Hardcore"<<endl;
        cin >> mode;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Saisie invalide : Mode Invalide" << endl;
            continue;
        }
        if (mode < 0 || mode > 4) {
            cout << "Saisie Mode Incorrect" << endl;
            mode = 0;
        }
        mode_jeu = mode ;

    } while (mode == 0) ;


    for(unsigned int i = 1 ; i <= nb_joueurs ; ++i)
    {
        cout << "Joueur numero " << i << ", " << endl;
        Joueur * j = new Joueur(mode_jeu);
        joueurs.push_back(j);
    }
    lancer = new Lancer();
}

void Jeu::tourdejeu() {
    clear_screen();
    cout << "###Tour de Jeu : " << tour << "###" << endl;
    for(Joueur *j : joueurs) {
        cout << "##Pour le joueur : " << j->getName() << "##" << endl << endl;

        for (int i = 0; i <=2; ++i) {
            lancer->rollDices();

            for (const auto& de : lancer->getDices()) {
                std::cout << de.getValue() << " ";
            }

            if (i < 2) {
                cout << endl;
                j->affichePreview(*lancer);
                cout << endl << "Est-ce que ce lancer vous convient? (o/n)" << endl;
                if (getPositiveAnswer())
                    break;

                short ind = 0;
                for (const auto& de : lancer->getDices()) {
                    ind++;
                    if (de.isLocked())
                        cout << "Voulez-vous liberer le de " << ind << "? (o/n)" << endl;
                    else
                        cout << "Voulez-vous bloquer le de " << ind << "? (o/n)" << endl;
                    if (getPositiveAnswer())
                        lancer->lockOrUnlockDice(ind-1);
                }
                clear_screen();
            }
        }
        clear_screen();
        cout << "Les des :" << endl;
        for (const auto& de : lancer->getDices()) {
            std::cout << de.getValue() << " ";
        }
        cout << endl << endl;
        j->affichePreview(*lancer);


        bool is_possible = false;
        unsigned int position;

        if(mode_jeu!=3 && mode_jeu!=4) {
            do {
                cout << "Quelle combinaison souhaitez-vous jouer?" << endl;
                cin >> position;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Saisie invalide. Entrez une position." << endl;
                    continue;
                }
                is_possible = j->setScore(*lancer, position-1);

            } while (!is_possible);
        }
        else
        {
            j->setScore(*lancer);
        }


        clear_screen();
        cout << "Dernier Lancer des des :" << endl;
        for (const auto& de : lancer->getDices()) {
            std::cout << de.getValue() << " ";
        }
        cout << endl << endl;
        cout << "Voici votre feuille de score a la fin du tour." << endl;
        j->affiche();
        lancer->remiseAzeroDe();
        cout << "Confirmez le passage au prochain joueur ou tour. (o)" << endl;
        while (!getPositiveAnswer()) {};
        clear_screen();
    }
    tour++;

}

void Jeu::clear_screen()
{
    system("cls||clear");
}

bool Jeu::getPositiveAnswer()
{
    char choix = 0;
    bool saisieValide = false;

    do {
        cin >> choix;

        if (choix == 'o' || choix == 'n') {
            saisieValide = true;
        }
        else {
            cout << "Réponse invalide. Veuillez réessayer." << endl;
        }
    } while (!saisieValide);

    return (choix == 'o');
}

void Jeu::LancerJeu() {
    while(tour <= 13)
    {
        tourdejeu();
    }
    cout << "Partie terminee. Voici les feuilles de scores de chaque joueur :" << endl;
    for (Joueur* j : joueurs) {
        j->affiche();
    }
    cout << endl << endl;
    cout << "Partie terminée. Les feuilles de scores sont au dessus. Confirmez la fermeture de la fenetre. (o)" << endl;
    while (!getPositiveAnswer()) {};
}

Jeu::~Jeu() {
    delete lancer;
    for(Joueur * j : joueurs)
    {
        delete j;
    }
}
