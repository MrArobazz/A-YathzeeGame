//
// Created by macine on 04/01/24.
//

#include "Jeu.h"

using namespace std;

Jeu::Jeu() {
    cout << "A combien souhaitez-vous jouer ?" << endl;
    unsigned int nb_joueurs;
    cin >> nb_joueurs;
    for(unsigned int i = 0 ; i < nb_joueurs ; ++i)
    {
        Joueur * j = new Joueur();
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
        do {
            cout << "Quelle combinaison souhaitez-vous jouer?" << endl;
            cin >> position;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Saisie invalide. Entrez une position." << endl;
                continue;
            }
            is_possible = j->setScore(*lancer, position);
            
        } while (!is_possible);

        clear_screen();
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
    //system("cls||clear");
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
}

Jeu::~Jeu() {
    delete lancer;
    for(int i = 0 ;i < joueurs.size() ; ++i)
    {
        delete joueurs[i];
    }
}
