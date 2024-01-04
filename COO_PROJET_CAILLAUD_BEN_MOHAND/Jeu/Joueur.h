//
// Created by macine on 04/01/24.
//

#ifndef COO_PROJET_CAILLAUD_BEN_MOHAND_JOUEUR_H
#define COO_PROJET_CAILLAUD_BEN_MOHAND_JOUEUR_H

#include "../Feuille_Score/Feuille_de_score.h"

class Joueur {
private:
    Feuille_de_score * feuille_score;
    std::string name;
public:
    Joueur();
    bool setScore(Lancer & lancer , unsigned int position);
    int getScore();
    void affiche();
};


#endif //COO_PROJET_CAILLAUD_BEN_MOHAND_JOUEUR_H
