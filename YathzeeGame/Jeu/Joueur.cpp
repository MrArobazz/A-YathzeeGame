//
// Created by macine on 04/01/24.
//

#include "Joueur.h"
using namespace std;

Joueur::Joueur(unsigned int mode) : feuille_score(mode) {
    mode_jeu = mode;
    cout << "Entrez votre Nom" << endl;
    cin >> name;

}

bool Joueur::setScore(Lancer &lancer, unsigned int position) {
    return feuille_score.setScore(lancer,position);
}

void Joueur::setScore(Lancer &lancer)
{
    feuille_score.setScore(lancer, feuille_score.getPositionActuelle());
    feuille_score.majpos();
 }

int Joueur::getScore() {
    return feuille_score.getScore();
}

std::string Joueur::getName()
{
    return name;
}

void Joueur::affiche() {
    cout << "Feuille de score de : " << name << endl;
    feuille_score.affiche();
    cout << "Score Total : " << feuille_score.getScore() << endl << endl << endl;
}

void Joueur::affichePreview(Lancer& lancer)
{
    cout << "#===SCORES POSSIBLE===#" << endl;
        feuille_score.affichePreview(lancer);
}

Joueur::~Joueur() {
}

std::ostream& operator<<(std::ostream& out, const Joueur& j)
{
    out << "Joueur:"
        << " " << j.name
        << " " << j.mode_jeu << endl;
    out << j.feuille_score;
    return out;
}
