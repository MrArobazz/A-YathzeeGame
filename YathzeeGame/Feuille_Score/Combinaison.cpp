//
// Created by macine on 03/01/24.
//

#include "Combinaison.h"

position::position(const int p, const int s) :pos(p),score(s){
}
void position::affiche()
{
    std::cout<<"position : "<<pos<<std::endl<<"score : "<<score<<std::endl;
}


Combinaison::Combinaison(std::shared_ptr<Figure> f,std::string Desc, int mean_score) : figure(f),description(Desc), mean_score(mean_score) {};

void Combinaison::setScore(const Lancer & lancer) {
    score = figure ? figure->calculerPoints(lancer) : 0;
}

void Combinaison::setPreviewScore(const Lancer& lancer)
{
    if (score == -1)
        preview_score = figure->calculerPoints(lancer);
}

void Combinaison::resetPreviewScore()
{
    preview_score = 0;
}

int Combinaison::getScore() const{
    return score;
}

void Combinaison::setPreviewBrelan(const Lancer& lancer)
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

void Combinaison::setPreviewCarre(const Lancer& lancer)
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


void Combinaison::affiche() {
    std::cout << description << " " << (score == -1 ? 0 : score) << std::endl;

}

void Combinaison::affichePreview()
{
    std::cout << description << " " << preview_score << std::endl;
}

void Combinaison::setFig(std::shared_ptr<Figure> f) {
    figure = f;
}

std::ostream& operator<<(std::ostream& out, const Combinaison& comb)
{
    out << "Combinaison:"
        << " " << comb.score
        << " " << comb.preview_score
        << std::endl;
    return out;
}

std::istream& operator>>(std::istream& input, Combinaison& comb)
{
    std::string prefix;
    input >> prefix
        >> comb.score
        >> comb.preview_score;
    return input;
}

int Combinaison::get_preview_score() const {
    if(score == -1)
        return preview_score;
    else
        return -1;
}

int Combinaison::getScoreMean() const {
    return mean_score;
}
