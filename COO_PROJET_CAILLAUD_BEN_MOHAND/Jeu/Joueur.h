//
// Created by macine on 04/01/24.
//

#pragma once
#include "../Feuille_Score/Feuille_de_score.h"

class Joueur {
private:
    Feuille_de_score* feuille_score;
    std::string name;
public:
    Joueur();
    bool setScore(Lancer & lancer , unsigned int position);
    int getScore();
    std::string getName();
    void affiche();

    void affichePreview(Lancer& lancer);
};
