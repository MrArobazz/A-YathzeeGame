//
// Created by macine on 04/01/24.
//

#include "Joueur.h"
using namespace std;

Joueur::Joueur(unsigned int mode , unsigned int bot, bool human) : feuille_score(mode),is_humain(human),type_joueur(bot){
    mode_jeu = mode;
    if (bot == 0) {
        cout << "Entrez votre Nom" << endl;
        cin >> name;
    } else if (bot == 1) {
        name = "Nicolas";
    } else
        name = "Hakim";
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
        << " " << j.mode_jeu
        << " " << j.is_humain
        << " " << j.type_joueur << endl;
    out << j.feuille_score;
    return out;
}

std::istream& operator>>(std::istream& input, Joueur& j)
{
    string prefix;
    input >> prefix
        >> j.name
        >> j.mode_jeu
        >> j.is_humain
        >> j.type_joueur
        >> j.feuille_score;
    return input;
}

const bool Joueur::is_human() {
    return is_humain;
}

int Joueur::get_pos_bot(Lancer & lancer) {
    return feuille_score.get_Bot_pos(lancer);
}

int Joueur::getScoreLancer(Lancer & lancer) {
    return feuille_score.getScoreLancer(lancer);
}
