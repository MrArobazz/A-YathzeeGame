//
// Created by macine on 03/01/24.
//

#include "Feuille_de_score.h"

Feuille_de_score::Feuille_de_score(unsigned int mode):section_b(),section_h() {
   Section_Haute h;
   h.affiche();
   section_h = h;
    switch (mode) {
        case 1 :
            break;
        case 2 :
            section_b.lock();
            break;
        case 3 :
            mode_difficil = true;
            break;
        case 4 :
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            mode_difficil = true;
            std::shuffle(position_possible.begin(),position_possible.end(),std::default_random_engine(seed));
    }

}

Feuille_de_score::Feuille_de_score(const Feuille_de_score &feuille_score) :position_actuel(feuille_score.position_actuel),
position_possible(feuille_score.position_possible),score_total(feuille_score.score_total),
mode_difficil(feuille_score.mode_difficil){
    section_h=feuille_score.section_h;
    section_b=feuille_score.section_b;
}

Feuille_de_score& Feuille_de_score::operator=(const Feuille_de_score &feuille_score) {
    if(this!=&feuille_score)
    {
        section_h = feuille_score.section_h;
        section_b = feuille_score.section_b;
        position_actuel = feuille_score.position_actuel;
        position_possible = feuille_score.position_possible;
        mode_difficil = feuille_score.mode_difficil;
    }
    return *this;
}

bool Feuille_de_score::setScore(Lancer &lancer, unsigned int position) {
    if(position < 13 )
    {
        Yams y;
        if(y.calculerPoints(lancer))
        {
            section_b.bonusYams();
        }
            if (position < 6) {
                if (section_h.getScorePosition(position) == -1) {
                    section_h.setScore(lancer, position);
                    score_total = section_h.getScore() + section_b.getScore();
                    if (section_h.is_full()) {
                        section_b.unlock();
                    }
                    return true;
                }

            } else {
                if (!section_b.islocked()) {
                    if (section_b.getScorePosition(position - 6) == -1) {
                        section_b.setScore(lancer, position - 6);
                        score_total = section_h.getScore() + section_b.getScore();
                        return true;
                    }
                }
            }
    }
        return false;
}

void Feuille_de_score::majpos()
{
    position_actuel++;
}


int Feuille_de_score::getScore() {
    return score_total;
}

void Feuille_de_score::affiche() {
    section_h.affiche();
    if(!section_b.islocked())
        section_b.affiche();
}

void Feuille_de_score::affichePreview(Lancer& lancer)
{
    if(!mode_difficil) {
        for (int position = 0; position < 13; position++) {
            if (position < 6) {
                if (section_h.getScorePosition(position) == -1) {
                    section_h.setPreviewScore(lancer, position);
                    section_h.affichePreview(position);
                }
            } else {
                if (!section_b.islocked()) {
                    if (section_b.getScorePosition(position - 6) == -1) {
                        section_b.setPreviewScore(lancer, position - 6);
                        section_b.affichePreview(position - 6);
                    }
                }
            }
        }
        section_h.resetPreviewScores();
        section_b.resetPreviewScores();
    }else
    {
        if(position_possible[position_actuel]<6)
        {
            section_h.setPreviewScore(lancer, position_possible[position_actuel]);
            section_h.affichePreview(position_possible[position_actuel]);
        }
        else
        {
            section_b.setPreviewScore(lancer, position_possible[position_actuel]-6);
            section_b.affichePreview(position_possible[position_actuel]-6);
        }
    }

}

Feuille_de_score::~Feuille_de_score() {
}

int Feuille_de_score::getPositionActuelle() {
    return position_possible[position_actuel];
}
