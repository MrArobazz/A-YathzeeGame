//
// Created by macine on 03/01/24.
//

#pragma once
#include "../Figures/Brelan.h"
#include "../Figures/Carre.h"
#include "../Figures/Chance.h"
#include "../Figures/Cinq.h"
#include "../Figures/Deux.h"
#include "../Figures/Full.h"
#include "../Figures/GrandeSuite.h"
#include "../Figures/PetiteSuite.h"
#include "../Figures/Quatre.h"
#include "../Figures/Six.h"
#include "../Figures/Trois.h"
#include "../Figures/Un.h"
#include "../Figures/Yams.h"


class Combinaison {

private:

    const Figure * figure;
    const std::string description;
    int score = -1;
    int preview_score = 0;

public:

    Combinaison(Figure *f,std::string Desc) ;
    Combinaison(const Combinaison &comb);
    Combinaison& operator=(const Combinaison &comb);

    void setScore(Lancer& lancer);
    void setPreviewScore(Lancer& lancer);
    void resetPreviewScore();
    int getScore();
    void setPreviewBrelan(Lancer& lancer);
    void setPreviewCarre(Lancer& lancer);


    std::string getDesc();
    void affiche();
    void affichePreview();

};
