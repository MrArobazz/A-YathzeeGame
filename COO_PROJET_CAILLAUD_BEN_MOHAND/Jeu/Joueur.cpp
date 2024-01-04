//
// Created by macine on 04/01/24.
//

#include "Joueur.h"

Joueur::Joueur() {
    feuille_score = new Feuille_de_score();
    std::cout<<"Entrez votre Nom"<<std::endl;
    std::cin>>name;
}

bool Joueur::setScore(Lancer &lancer, unsigned int position) {
    return feuille_score->setScore(lancer,position);
}

int Joueur::getScore() {
    return feuille_score->getScore();
}

void Joueur::affiche() {
    std::cout<<"Feuille de score de  : "<<name<<std::endl;
    feuille_score->affiche();
    std::cout<<"Score Total : "<<feuille_score->getScore()<<std::endl;
}
