//
// Created by macine on 03/01/24.
//

#ifndef COO_PROJET_CAILLAUD_BEN_MOHAND_COMBINAISON_H
#define COO_PROJET_CAILLAUD_BEN_MOHAND_COMBINAISON_H

#include "Figures/Brelan.h"
#include "Figures/Carre.h"
#include "Figures/Chance.h"
#include "Figures/Cinq.h"
#include "Figures/Deux.h"
#include "Figures/Full.h"
#include "Figures/GrandeSuite.h"
#include "Figures/PetiteSuite.h"
#include "Figures/Quatre.h"
#include "Figures/Six.h"
#include "Figures/Trois.h"
#include "Figures/Un.h"
#include "Figures/Yams.h"


class Combinaison {
private:
    const Figure &figure;
    const std::string Description;
    int Score = -1;
public:
    Combinaison(Figure &f,std::string Desc) : figure(f),Description(Desc) {};
    void setScore(Lancer & lancer);
    int getScore();
    void setBrelan(Lancer & lancer);
    void setCarre(Lancer & lancer);
    std::string getDesc();
    void affiche();

};


#endif //COO_PROJET_CAILLAUD_BEN_MOHAND_COMBINAISON_H
