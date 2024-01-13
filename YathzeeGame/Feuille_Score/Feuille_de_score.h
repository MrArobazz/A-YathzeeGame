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
    int scorelancer = 0;

public:
    Feuille_de_score(unsigned int mode);
    Feuille_de_score() : section_h(), section_b() {}; // pour eviter le usage du constructeur au dessus (qui utilise cin) pour la save

    bool setScore(Lancer & lancer , unsigned int position);
    int getScore()const;
    void affiche();
    void affichePreview(Lancer& lancer);
    int getPositionActuelle();
    void majpos();

    void get_combinaison(std::vector<position>&pos);
    void get_Bot_pos(Lancer & lancer, std::vector<position> &pos);


    int getScoreMean(unsigned int position) const;

    void setScoreLancer(std::vector<position> &pos);
    int getScoreLancer(Lancer & lancer);


    friend std::ostream& operator<<(std::ostream& out, const Feuille_de_score& fds);
    friend std::istream& operator>>(std::istream& input, Feuille_de_score& fds);
};
