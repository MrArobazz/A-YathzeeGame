//
// Created by macine on 04/01/24.
//

#pragma once
#include "../Feuille_Score/Feuille_de_score.h"

class Joueur {
private:
    Feuille_de_score feuille_score;
    std::string name;
    unsigned int mode_jeu;
public:
    Joueur(unsigned int mode);
    Joueur() : feuille_score(), name("MIIIIICHEEEEEEL"), mode_jeu(1) {}; // pour eviter le usage du constructeur au dessus (qui utilise cin) pour la save

    bool setScore(Lancer & lancer , unsigned int position);
    void setScore(Lancer & lancer);
    int getScore();
    std::string getName();
    void affiche();

    void affichePreview(Lancer& lancer);

    ~Joueur();

    friend std::ostream& operator<<(std::ostream& out, const Joueur& j);
    friend std::istream& operator>>(std::istream& input, Joueur& j);
};
