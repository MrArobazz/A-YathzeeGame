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
#include <memory>

class Combinaison {

private:

    std::shared_ptr<Figure> figure;
    const std::string description;
    int score = -1;
    int preview_score = 0;

public:

    Combinaison(std::shared_ptr<Figure> f,std::string Desc) ;
    void setScore(Lancer& lancer);
    void setPreviewScore(Lancer& lancer);
    void resetPreviewScore();
    int getScore();
    void setPreviewBrelan(Lancer& lancer);
    void setPreviewCarre(Lancer& lancer);
    void setFig(std::shared_ptr<Figure> f);


    std::string getDesc();
    void affiche();
    void affichePreview();

    friend std::ostream& operator<<(std::ostream& out, const Combinaison& comb);
};