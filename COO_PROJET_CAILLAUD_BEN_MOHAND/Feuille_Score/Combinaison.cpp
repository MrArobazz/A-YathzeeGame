//
// Created by macine on 03/01/24.
//

#include "Combinaison.h"
void Combinaison::setScore(Lancer & lancer) {
    score = figure->calculerPoints(lancer);
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

void Combinaison::setBrelan(Lancer &lancer) {
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int brelan = 0;
    if(desTries[0]==desTries[2] )
    {
        brelan = desTries[0];
    }
    else
    {
        if (desTries[1]==desTries[3])
        {
            brelan = desTries[1];
        }
        else
        {
            if(desTries[2]==desTries[4])
            {
                brelan = desTries[2];
            }
        }
    }

    switch (brelan) {
        case 1: {
            Un u;
            figure = new Brelan<Un>(u);
            break;
        }
        case 2: {
            Deux d;
            figure = new Brelan<Deux>(d);
            break;
        }
        case 3: {
            Trois t;
            figure = new Brelan<Trois>(t);
            break;
        }
        case 4: {
            Quatre q;
            figure = new Brelan<Quatre>(q);
            break;
        }
        case 5: {
            Cinq c;
            figure = new Brelan<Cinq>(c);
            break;
        }
        case 6: {
            Six s;
            figure = new Brelan<Six>(s);
            break;
        }
    }

    score = figure ? figure->calculerPoints(lancer) : 0; 
}

void Combinaison::setCarre(Lancer &lancer) {
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int carre = 0;
    if(desTries[0]==desTries[3] )
    {
        carre = desTries[0];
    }
    else
    {
        if (desTries[1] == desTries[4]) {
            carre = desTries[1];
        }
    }

    switch(carre) {
        case 1: {
            Un u;
            figure = new Carre<Un>(u);
            break;
        }
        case 2: {
            Deux d;
            figure = new Carre<Deux>(d);
            break;
        }
        case 3: {
            Trois t;
            figure = new Carre<Trois>(t);
            break;
        }
        case 4: {
            Quatre q;
            figure = new Carre<Quatre>(q);
            break;
        }
        case 5: {
            Cinq c;
            figure = new Carre<Cinq>(c);
            break;
        }
        case 6: {
            Six s;
            figure = new Carre<Six>(s);
            break;
        }
    }

    score = figure ? figure->calculerPoints(lancer) : 0;
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
