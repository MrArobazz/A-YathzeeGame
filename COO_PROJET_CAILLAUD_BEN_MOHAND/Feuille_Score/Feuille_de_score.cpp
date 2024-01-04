//
// Created by macine on 03/01/24.
//

#include "Feuille_de_score.h"

Feuille_de_score::Feuille_de_score() {
    section_h = new Section_Haute();
    section_b = new Section_Basse();
}

bool Feuille_de_score::setScore(Lancer &lancer, unsigned int position) {
    if(position <= 14 && position > 0)
    {
        if(position <=6)
        {
            if(section_h->getScorePosition(position-1) == -1)
            {
                section_h->setScore(lancer,position-1);
                score_total = section_h->getScore() + section_b->getScore();
                section_h->getDescCombinaison(position);
                return true;
            }

        }
        else
        {
            if(section_b->getScorePosition(position-7) == -1)
            {
                section_b->setScore(lancer,position-7);
                score_total = section_h->getScore() + section_b->getScore();
                std::cout<<section_b->getDescCombinaison(position-7)<<std::endl;
                return true;
            }
        }
    }
        return false;
}

int Feuille_de_score::getScore() {
    return score_total;
}

void Feuille_de_score::affiche() {
    section_h->affiche();
    section_b->affiche();
}