//
// Created by macine on 04/01/24.
//

#pragma once
#include "Joueur.h"
#include <limits>

class Jeu {
private:
    Lancer* lancer;
    std::vector<Joueur *> joueurs;
    int tour = 1;
    void tourdejeu();
    void clear_screen();
    bool getPositiveAnswer();

public :
    Jeu();
    void LancerJeu();

};
