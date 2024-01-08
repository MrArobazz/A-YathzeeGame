//
// Created by macine on 03/01/24.
//

#pragma once
#include "Section_Haute.h"
#include "Section_Basse.h"
#include <chrono>
#include <random>
class Feuille_de_score {

private:
    int position_actuel = 0;
    std::vector<int> position_possible={0,1,2,3,4,5,6,7,8,9,10,11,12};
    int score_total = 0;
    Section_Haute section_h;
    Section_Basse section_b;
    bool mode_difficil = false;

public:
    Feuille_de_score(unsigned int mode);
    Feuille_de_score(const Feuille_de_score &feuille_score);
    Feuille_de_score& operator=(const Feuille_de_score &feuille_score);

    bool setScore(Lancer & lancer , unsigned int position);
    int getScore();
    void affiche();
    void affichePreview(Lancer& lancer);
    int getPositionActuelle();
    void majpos();
    ~Feuille_de_score();
};
