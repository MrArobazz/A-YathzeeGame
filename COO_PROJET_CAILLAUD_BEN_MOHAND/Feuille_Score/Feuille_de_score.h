//
// Created by macine on 03/01/24.
//

#pragma once
#include "Section_Haute.h"
#include "Section_Basse.h"

class Feuille_de_score {

private:
    int position_actuel = 0;
    int score_total = 0;
    Section_Haute * section_h;
    Section_Basse * section_b;

public:
    Feuille_de_score();
    bool setScore(Lancer & lancer , unsigned int position);
    int getScore();
    void affiche();
    void affichePreview(Lancer& lancer);
};
