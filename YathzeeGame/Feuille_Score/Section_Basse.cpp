//
// Created by macine on 03/01/24.
//

#include "Section_Basse.h"

Section_Basse::Section_Basse() {
    std::shared_ptr<Figure> figure1 = nullptr;
    figures.push_back(figure1);
    std::shared_ptr<Figure> figure2 = nullptr;
    figures.push_back(figure2);
    std::shared_ptr<Figure> figure3 = std::make_shared<Full>();
    figures.push_back(figure3);
    std::shared_ptr<Figure> figure4 = std::make_shared<PetiteSuite>();
    figures.push_back(figure4);
    std::shared_ptr<Figure> figure5 = std::make_shared<GrandeSuite>();
    figures.push_back(figure5);
    std::shared_ptr<Figure> figure6 = std::make_shared<Yams>();
    figures.push_back(figure6);
    std::shared_ptr<Figure> figure7 = std::make_shared<Chance>();
    figures.push_back(figure7);

    section.push_back(Combinaison(figure1 , "Brelan (somme des 3 des) :"));
    section.push_back(Combinaison(figure2 , "Carre (somme des 4 des) :"));
    section.push_back(Combinaison(figure3 , "Full :"));
    section.push_back(Combinaison(figure4 , "Petite Suite :"));
    section.push_back(Combinaison(figure5 , "Grande Suite : "));
    section.push_back(Combinaison(figure6 , "Yams :"));
    section.push_back(Combinaison(figure7 , "Chance (Somme des 5 des) :"));
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
            figures[0] = std::make_shared<Brelan<Un> >(u);
            break;
        }
        case 2: {
            Deux d;
            figures[0] = std::make_shared<Brelan<Deux> >(d);
            break;
        }
        case 3: {
            Trois t;
            figures[0] = std::make_shared<Brelan<Trois> >(t);
            break;
        }
        case 4: {
            Quatre q;
            figures[0] =std::make_shared<Brelan<Quatre> >(q);
            break;
        }
        case 5: {
            Cinq c;
            figures[0] = std::make_shared<Brelan<Cinq> >(c);
            break;
        }
        case 6: {
            Six s;
            figures[0] = std::make_shared<Brelan<Six> >(s);;
            break;
        }
    }
    section[0].setFig(figures[0]);
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
            figures[1] = std::make_shared<Carre<Un> >(u);
            break;
        }
        case 2: {
            Deux d;
            figures[1]  = std::make_shared<Carre<Deux> >(d);
            break;
        }
        case 3: {
            Trois t;
            figures[1]  = std::make_shared<Carre<Trois> >(t);
            break;
        }
        case 4: {
            Quatre q;
            figures[1]  = std::make_shared<Carre<Quatre> >(q);
            break;
        }
        case 5: {
            Cinq c;
            figures[1]  = std::make_shared<Carre<Cinq> >(c);
            break;
        }
        case 6: {
            Six s;
            figures[1]  = std::make_shared<Carre<Six> >(s);
            break;
        }
    }
    section[1].setFig(figures[1]);
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
