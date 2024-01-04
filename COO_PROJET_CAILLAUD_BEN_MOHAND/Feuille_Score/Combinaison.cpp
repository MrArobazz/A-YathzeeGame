//
// Created by macine on 03/01/24.
//

#include "Combinaison.h"
void Combinaison::setScore(Lancer & lancer) {
    Score = figure.calculerPoints(lancer);
}

int Combinaison::getScore() {
    return Score;
}

void Combinaison::setBrelan(Lancer &lancer) {
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    int valeur_brelan = 0;
    if(desTries[0]==desTries[2] )
    {
        valeur_brelan = desTries[0];
    }
    else
    {
        if (desTries[1]==desTries[3])
        {
            valeur_brelan = desTries[1];
        }
        else
        {
            if(desTries[2]==desTries[4])
            {
                valeur_brelan = desTries[2];
            }
        }
    }

    Score = valeur_brelan * 3 ;
}

void Combinaison::setCarre(Lancer &lancer) {
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    int valeur_carre = 0;
    if(desTries[0]==desTries[3] )
    {
        valeur_carre = desTries[0];
    }
    else
    {
        if (desTries[1] == desTries[4]) {
            valeur_carre = desTries[1];
        }
    }

    Score = valeur_carre * 4 ;
}

std::string Combinaison::getDesc() {
    return Description;
}

void Combinaison::affiche() {
    std::cout<<Description<<" "<<Score<<std::endl;

}
