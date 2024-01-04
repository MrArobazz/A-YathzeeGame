//
// Created by macine on 04/01/24.
//

#ifndef COO_PROJET_CAILLAUD_BEN_MOHAND_JEU_H
#define COO_PROJET_CAILLAUD_BEN_MOHAND_JEU_H

#include "Joueur.h"

class Jeu {
private:
    Lancer * lancer;
    std::vector<Joueur *> joueurs;
    int tour = 1;
    void tourdejeu();

public :
    Jeu();
    void LancerJeu();

};


#endif //COO_PROJET_CAILLAUD_BEN_MOHAND_JEU_H
