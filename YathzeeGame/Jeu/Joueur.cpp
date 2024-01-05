//
// Created by macine on 04/01/24.
//

#include "Joueur.h"
using namespace std;

Joueur::Joueur() {
    feuille_score = new Feuille_de_score();
    cout << "Entrez votre Nom" << endl;
    cin >> name;

}

bool Joueur::setScore(Lancer &lancer, unsigned int position) {
    return feuille_score->setScore(lancer,position);
}

int Joueur::getScore() {
    return feuille_score->getScore();
}

std::string Joueur::getName()
{
    return name;
}

void Joueur::affiche() {
    cout << "Feuille de score de : " << name << endl;
    feuille_score->affiche();
    cout << "Score Total : " << feuille_score->getScore() << endl << endl << endl;
}

void Joueur::affichePreview(Lancer& lancer)
{
    cout << "#===SCORES POSSIBLE===#" << endl;
    feuille_score->affichePreview(lancer);
}

Joueur::~Joueur() {
    delete feuille_score;
}
