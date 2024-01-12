//
// Created by macine on 03/01/24.
//

#pragma once
#include "Combinaison.h"

class Section_Basse {

private:
    std::vector<std::shared_ptr<Figure>> figures;
    std::vector<Combinaison> section;
    int score_section = 0;
    bool locked = false;
    bool bonus = false;
    void addBonus();
    void setBrelan(Lancer &lancer);
    void setCarre(Lancer &lancer);

public:

    Section_Basse();


    void setScore(Lancer & lancer, unsigned int position);
    int getScore();
    int getScorePosition(unsigned int position);
    void affiche();
    void bonusYams();
    bool islocked();
    void unlock();
    void lock();

    void setPreviewScore(Lancer& lancer, unsigned int position);
    void resetPreviewScores();
    void affichePreview(unsigned int position);

    friend std::ostream& operator<<(std::ostream& out, const Section_Basse& sb);
    friend std::istream& operator>>(std::istream& input, Section_Basse& sb);
};
