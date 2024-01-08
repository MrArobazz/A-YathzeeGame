//
// Created by macine on 03/01/24.
//

#include "Section_Basse.h"

Section_Basse::Section_Basse() {
    Figure * f1 = nullptr;
    figures.push_back(f1);
    Figure * f2 = nullptr;
    figures.push_back(f2);
    Figure * f3 = new Full();
    figures.push_back(f3);
    Figure * f4 = new PetiteSuite();
    figures.push_back(f4);
    Figure * f5 = new GrandeSuite();
    figures.push_back(f5);
    Figure * f6 = new Yams();
    figures.push_back(f6);
    Figure * f7 = new Chance();
    figures.push_back(f7);

    section.push_back(Combinaison(f1 , "Brelan (somme des 3 des) :"));
    section.push_back(Combinaison(f2 , "Carre (somme des 4 des) :"));
    section.push_back(Combinaison(f3 , "Full :"));
    section.push_back(Combinaison(f4 , "Petite Suite :"));
    section.push_back(Combinaison(f5 , "Grande Suite : "));
    section.push_back(Combinaison(f6 , "Yams :"));
    section.push_back(Combinaison(f7 , "Chance (Somme des 5 des) :"));
}


void Section_Basse::setBrelan(Lancer &lancer) {
    int desTries[5]{};
    int ind = 0;
    for (const auto &de: lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int brelan = 0;
    if (desTries[0] == desTries[2]) {
        brelan = desTries[0];
    } else {
        if (desTries[1] == desTries[3]) {
            brelan = desTries[1];
        } else {
            if (desTries[2] == desTries[4]) {
                brelan = desTries[2];
            }
        }
    }

    switch (brelan) {
        case 1: {
            Un u;
            figures[0] = new Brelan<Un>(u);
            break;
        }
        case 2: {
            Deux d;
            figures[0] = new Brelan<Deux>(d);
            break;
        }
        case 3: {
            Trois t;
            figures[0] = new Brelan<Trois>(t);
            break;
        }
        case 4: {
            Quatre q;
            figures[0] = new Brelan<Quatre>(q);
            break;
        }
        case 5: {
            Cinq c;
            figures[0] = new Brelan<Cinq>(c);
            break;
        }
        case 6: {
            Six s;
            figures[0] = new Brelan<Six>(s);
            break;
        }
    }
}


void Section_Basse::setCarre(Lancer &lancer) {
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
            figures[1] = new Carre<Un>(u);
            break;
        }
        case 2: {
            Deux d;
            figures[1]  = new Carre<Deux>(d);
            break;
        }
        case 3: {
            Trois t;
            figures[1]  = new Carre<Trois>(t);
            break;
        }
        case 4: {
            Quatre q;
            figures[1]  = new Carre<Quatre>(q);
            break;
        }
        case 5: {
            Cinq c;
            figures[1]  = new Carre<Cinq>(c);
            break;
        }
        case 6: {
            Six s;
            figures[1]  = new Carre<Six>(s);
            break;
        }
    }
}


void Section_Basse::setScore(Lancer &lancer, unsigned int position) {

    if(position == 0)
    {
        setBrelan(lancer);
    }
    if(position == 1)
    {
        setCarre(lancer);
    }

    section[position].setScore(lancer);
    score_section += section[position].getScore();
}

int Section_Basse::getScore() {
    return score_section;
}

int Section_Basse::getScorePosition(unsigned int position) {
    return section[position].getScore();
}


void Section_Basse::affiche() {
    for(int i = 0 ; i < section.size() ; ++i){
        std::cout<<7+i<<"-";
        section[i].affiche();
    }
}

void Section_Basse::setPreviewScore(Lancer& lancer, unsigned int position)
{
    if (position == 0)
    {
        section[0].setPreviewBrelan(lancer);
    }
    else
    {
        if (position == 1)
        {
            section[1].setPreviewCarre(lancer);
        }
        else
        {
            section[position].setPreviewScore(lancer);
        }
    }
}

void Section_Basse::resetPreviewScores()
{
    for (Combinaison fig : section)
        fig.resetPreviewScore();
}

void Section_Basse::affichePreview(unsigned int position)
{
    std::cout << 7 + position << "-";
    section[position].affichePreview();
}


void Section_Basse::addBonus() {
    if(!bonus){
        score_section+= 100;
        bonus = true;
    }
}

void Section_Basse::bonusYams() {
    if(section[5].getScore() == 50)
    {
        addBonus();
    }
}

bool Section_Basse::islocked() {
    return locked;
}

void Section_Basse::unlock() {
    locked = false;
}

void Section_Basse::lock() {
    locked = true ;
}

Section_Basse::~Section_Basse() {

    for(Figure *f : figures)
    {
        if(f)
        {
            delete f;
        }
    }
}