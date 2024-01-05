//
// Created by macine on 03/01/24.
//

#include "Feuille_de_score.h"

Feuille_de_score::Feuille_de_score() {
    section_h = new Section_Haute();
    section_b = new Section_Basse();
}

bool Feuille_de_score::setScore(Lancer &lancer, unsigned int position) {
    if(position >= 1 && position <= 13)
    {
        if(position <=6)
        {
            if(section_h->getScorePosition(position-1) == -1)
            {
                section_h->setScore(lancer,position-1);
                score_total = section_h->getScore() + section_b->getScore();
                return true;
            }

        }
        else
        {
            if(section_b->getScorePosition(position-7) == -1)
            {
                section_b->setScore(lancer,position-7);
                score_total = section_h->getScore() + section_b->getScore();
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

void Feuille_de_score::affichePreview(Lancer& lancer)
{
    for (int position = 1; position <= 13; position++)
    {
        if (position <= 6)
        {
            if (section_h->getScorePosition(position - 1) == -1)
            {
                section_h->setPreviewScore(lancer, position - 1);
                section_h->affichePreview(position - 1);
                section_h->resetPreviewScores();
            }
        }
        else
        {
            if (section_b->getScorePosition(position - 7) == -1)
            {
                section_b->setPreviewScore(lancer, position - 7);
                section_b->affichePreview(position - 7);
                section_b->resetPreviewScores();
            }
        }
    }
}

Feuille_de_score::~Feuille_de_score() {
    delete section_b;
    delete section_h;
}
