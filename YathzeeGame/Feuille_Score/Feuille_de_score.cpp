//
// Created by macine on 03/01/24.
//

#include "Feuille_de_score.h"

Feuille_de_score::Feuille_de_score(unsigned int mode):section_h(),section_b(){
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
            auto rng = std::default_random_engine{};
            mode_difficil = true;
            std::shuffle(position_possible.begin(), position_possible.end(), rng);
    }

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

int Feuille_de_score::getPositionActuelle() {
    return position_possible[position_actuel];
}

std::ostream& operator<<(std::ostream& out, const Feuille_de_score& fds)
{
    out << "Feuille_de_score:"
        << " " << fds.position_actuel;
    for (const int& pos : fds.position_possible)
        out << " " << pos;
    out << " " << fds.score_total
        << " " << fds.mode_difficil << std::endl;
    out << fds.section_h << fds.section_b;
    return out;
}

std::istream& operator>>(std::istream& input, Feuille_de_score& fds)
{
    std::string prefix;
    input >> prefix
        >> fds.position_actuel;
    std::vector<int> positions;
    for (int i = 0; i < 13; i++) {
        int tmp = 0;
        input >> tmp;
        positions.push_back(tmp);
    }
    fds.position_possible = positions;
    input >> fds.score_total
        >> fds.mode_difficil
        >> fds.section_h
        >> fds.section_b;
    return input;
}
