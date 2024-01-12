//
// Created by macine on 04/01/24.
//

#pragma once
#include "Joueur.h"
#include <limits>
#include <iostream>
#include <fstream>

class Jeu {
private:
    Lancer lancer;
    std::vector<std::shared_ptr<Joueur>> joueur;
    unsigned int mode_jeu = 1;
    int tour = 1;
    void tourdejeu();
    void clear_screen();
    bool getPositiveAnswer();

public :
    Jeu();
    void LancerJeu();

    friend std::ostream& operator<<(std::ostream& out, const Jeu& j);
    friend std::istream& operator>>(std::istream& input, Jeu& j);

};
