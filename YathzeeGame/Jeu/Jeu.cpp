//
// Created by macine on 04/01/24.
//

#include "Jeu.h"

using namespace std;

Jeu::Jeu() : lancer(){

    unsigned int nb_joueurs = 0;
    unsigned int mode = 0 ;

    string fileName = "save.txt";

    ifstream inputFile(fileName);
    bool newGame = true;
    if (inputFile.good()) {
        cout << "Une sauvegarde a ete trouvee. Voulez-vous la charger? (o/n)" << endl;
        if (getPositiveAnswer()) {
            inputFile >> *this;

            cout << "La sauvegarde a ete chargee." << endl;
            newGame = false;
        }
        inputFile.close();
        cout << "Voulez-vous la supprimer? (o/n)" << endl;
        if (getPositiveAnswer())
            if (remove(fileName.c_str()) == 0)
                cout << "Fichier supprime." << endl;
            else
                cerr << "Suppression impossible." << endl;
    }

    if (newGame) {
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

        } while (nb_joueurs == 0);



        do {
            cout << "Choisir un Mode de Jeu" << endl;
            cout << "1 : mode Facile" << endl;
            cout << "2 : mode Normal" << endl;
            cout << "3 : mode Difficile" << endl;
            cout << "4 : mode Hardcore" << endl;
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
            mode_jeu = mode;

        } while (mode == 0);




        for(unsigned int i = 1 ; i <= nb_joueurs ; ++i)
        {
            cout << "Joueur numero " << i << ", " << endl;
            cout << "Type joueur : " << endl;
            cout << "1 - Humain" << endl;
            cout << "2 - Nicolas" << endl;
            cout << "3 - Hakim" << endl;
            int type = 0;
            cin>>type;
            if(type == 1){
                std::shared_ptr<Joueur> joueur1 = std::make_shared<Joueur>(mode_jeu,0);
                joueur.push_back(joueur1);
            }else{
                if(type== 2)
                {
                    std::shared_ptr<Joueur> joueur1 = std::make_shared<Joueur>(mode_jeu,1, false);
                    joueur.push_back(joueur1);
                }else{
                    cout<<" Redoublement "<<endl;
                    std::shared_ptr<Joueur> joueur1 = std::make_shared<Joueur>(mode_jeu,2, false);
                    joueur.push_back(joueur1);
                }
            }

        }


    }
}

void Jeu::tourdejeu() {
    clear_screen();
    cout << "###Tour de Jeu : " << tour << "###" << endl;
    for(std::shared_ptr<Joueur> &j : joueur) {
        cout << "##Pour le joueur : " << j->getName() << "##" << endl << endl;

        for (int i = 0; i <=2; ++i) {
            lancer.rollDices();

            
            if(j->is_human()) {
                for (const auto& de : lancer.getDices()) {
                    std::cout << de.getValue() << " ";
                }
                if (i < 2) {
                    cout << endl;
                    j->affichePreview(lancer);
                    cout << endl << "Est-ce que ce lancer vous convient? (o/n)" << endl;
                    if (getPositiveAnswer())
                        break;

                    short ind = 0;
                    for (const auto &de: lancer.getDices()) {
                        ind++;
                        if (de.isLocked())
                            cout << "Voulez-vous liberer le de " << ind << "? (o/n)" << endl;
                        else
                            cout << "Voulez-vous bloquer le de " << ind << "? (o/n)" << endl;
                        if (getPositiveAnswer())
                            lancer.lockOrUnlockDice(ind - 1);
                    }
                    clear_screen();
                }
            }else{
                if((j->getScoreLancer(lancer)>=52 && (mode_jeu == 1)) || ((j->getScoreLancer(lancer)>15) && (mode_jeu !=1)))
                    break;
            }
        }
        clear_screen();
        cout << "Les des :" << endl;
        for (const auto& de : lancer.getDices()) {
            std::cout << de.getValue() << " ";
        }
        cout << endl << endl;


        bool is_possible = false;
        unsigned int position;

        if(mode_jeu!=3 && mode_jeu!=4) {
            if (!j->is_human()) {
                j->setScore(lancer, j->get_pos_bot(lancer));
            } else {
                j->affichePreview(lancer);
                do {
                    cout << "Quelle combinaison souhaitez-vous jouer?" << endl;
                    cin >> position;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Saisie invalide. Entrez une position." << endl;
                        continue;
                    }
                    is_possible = j->setScore(lancer, position - 1);

                } while (!is_possible);
                clear_screen();
            }
        }
        else
        {
            j->setScore(lancer);
        }


        cout << "Voici votre feuille de score a la fin du tour." << endl;
        j->affiche();
        lancer.remiseAzeroDe();
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
        cout << "Voulez-vous sauvegarder la partie? (o/n)" << endl;
        if (getPositiveAnswer()) {
            string fileName = "save.txt";
            ofstream outputFile(fileName, std::ios::out);

            if (outputFile.is_open()) {
                outputFile << *this;
                outputFile.close();

                cout << "La partie a bien ete sauvegardee." << endl;
                cout << "Voulez-vous quitter le jeu? (o/n)" << endl;
                if (getPositiveAnswer())
                    return;
            }
            else
                cerr << "Impossible de sauvegarder." << endl;
        }
    }
    cout << "Partie terminee. Voici les feuilles de scores de chaque joueur :" << endl;
    for (std::shared_ptr<Joueur> &j : joueur) {
        j->affiche();
    }
    cout << endl << endl;
    cout << "Partie terminee. Les feuilles de scores sont au dessus. Confirmez la fermeture de la fenetre. (o)" << endl;
    while (!getPositiveAnswer()) {};
}

std::ostream& operator<<(std::ostream& out, const Jeu& j)
{
    out << "Jeu:"
        << " " << j.mode_jeu
        << " " << j.tour
        << " " << j.joueur.size() << endl;
    for (const auto& joueur : j.joueur)
        out << *joueur;
    return out;
}

std::istream& operator>>(std::istream& input, Jeu& j)
{
    string prefix = "";
    input >> prefix
        >> j.mode_jeu
        >> j.tour;
    unsigned int nb_joueurs = 0;
    input >> nb_joueurs;
    for (unsigned int i = 1; i <= nb_joueurs; ++i)
    {
        std::shared_ptr<Joueur> joueur = std::make_shared<Joueur>();
        j.joueur.push_back(joueur);
    }
    for (auto& joueur : j.joueur)
        input >> *joueur;
    return input;
}
