//
// Created by macine on 03/01/24.
//

#include "Combinaison.h"

Combinaison::Combinaison(Figure *f,std::string Desc) : figure(f),description(Desc) {};

Combinaison::Combinaison(const Combinaison &com) :figure(com.figure),
description(com.description),score(com.score),preview_score(com.preview_score) {
}

Combinaison& Combinaison::operator=(const Combinaison &comb) {
    if(this!=&comb)
    {
        figure = comb.figure;
        static_cast<std::string>(description) = comb.description;
        score = comb.score;
        preview_score = comb.preview_score;
    }
    return *this;
}

void Combinaison::setScore(Lancer & lancer) {
    score = figure ? figure->calculerPoints(lancer) : 0;
}

void Combinaison::setPreviewScore(Lancer& lancer)
{
    if (score == -1)
        preview_score = figure->calculerPoints(lancer);
}

void Combinaison::resetPreviewScore()
{
    preview_score = 0;
}

int Combinaison::getScore() {
    return score;
}

void Combinaison::setPreviewBrelan(Lancer& lancer)
{
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int valeur_brelan = 0;
    if (desTries[0] == desTries[2])
    {
        valeur_brelan = desTries[0];
    }
    else
    {
        if (desTries[1] == desTries[3])
        {
            valeur_brelan = desTries[1];
        }
        else
        {
            if (desTries[2] == desTries[4])
            {
                valeur_brelan = desTries[2];
            }
        }
    }
    preview_score = valeur_brelan * 3;
}

void Combinaison::setPreviewCarre(Lancer& lancer)
{
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int valeur_carre = 0;
    if (desTries[0] == desTries[3])
    {
        valeur_carre = desTries[0];
    }
    else
    {
        if (desTries[1] == desTries[4]) {
            valeur_carre = desTries[1];
        }
    }
    preview_score = valeur_carre * 4;
}

std::string Combinaison::getDesc() {
    return description;
}

void Combinaison::affiche() {
    std::cout << description << " " << (score == -1 ? 0 : score) << std::endl;

}

void Combinaison::affichePreview()
{
    std::cout << description << " " << preview_score << std::endl;
}


