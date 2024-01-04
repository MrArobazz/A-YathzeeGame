//
// Created by macine on 04/01/24.
//

#include "Jeu.h"

Jeu::Jeu() {
    std::cout<<"A combien souhaitez-vous jouer ?";
    unsigned int nb_joueurs;
    std::cin>>nb_joueurs;
    for(int i = 0 ; i < nb_joueurs ; ++i)
    {
        Joueur * j = new Joueur();
        joueurs.push_back(j);
    }
    lancer = new Lancer();
}

void Jeu::tourdejeu() {
    int to_lock;
    std::cout<<std::endl<<"Tour de Jeu : "<<tour<<std::endl;
    for(int num_j = 0 ; num_j < joueurs.size() ; ++num_j) {
        for (int i = 0; i <=2; ++i) {
            lancer->rollDices();

            if (i < 2) {
                for (const auto &de: lancer->getDices()) {
                    std::cout << de.getValue() << " ";
                }
                std::cout << std::endl;
                for (int j = 1; j <= 5; ++j) {
                    std::cout << "Voulez-vous bloquer le dé : " << j << std::endl;
                    std::cin >> to_lock;
                    if (to_lock) {
                        lancer->lockOrUnlockDice(j - 1);
                    }
                }
            }
            else
            {
                std::cout<<"Lancer Final"<<std::endl;

                for (const auto &de: lancer->getDices()) {
                    std::cout << de.getValue() << " ";
                }
                std::cout << std::endl;

            }

        }

        //Affichage des Combinaison a Jouer
        joueurs[num_j]->affiche();


        bool is_possible = false;
        unsigned int position;
        while (!is_possible) {
            std::cout << "Quelle combinaison souhaitez-vous jouer?" << std::endl;
            std::cin>>position;
            is_possible = joueurs[num_j]->setScore(*lancer,position);
        }

        joueurs[num_j]->affiche();
        lancer->remiseAzeroDe();
    }
    tour++;

}

void Jeu::LancerJeu() {
    while(tour < 13)
    {
        tourdejeu();
    }
}