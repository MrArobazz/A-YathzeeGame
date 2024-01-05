//
// Created by macine on 03/01/24.
//

#include "Section_Basse.h"

Section_Basse::Section_Basse() {
    Figure * f1 = nullptr;
    Figure * f2 = nullptr;
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
    section.push_back(Combinaison(f3 , "Full (25 points) :"));
    section.push_back(Combinaison(f4 , "Petite Suite (30 points) :"));
    section.push_back(Combinaison(f5 , "Grande Suite (40 points) : "));
    section.push_back(Combinaison(f6 , "Yams (50 points) :"));
    section.push_back(Combinaison(f7 , "Chance (Somme des 5 des) :"));
}

void Section_Basse::setScore(Lancer &lancer, unsigned int position) {
    if(position == 0)
    {
        section[0].setBrelan(lancer);
    }
    else
    {
        if(position == 1)
        {
            section[1].setCarre(lancer);
        }
        else
        {
            section[position].setScore(lancer);
        }
    }
    score_section += section[position].getScore();
}

int Section_Basse::getScore() {
    return score_section;
}

int Section_Basse::getScorePosition(unsigned int position) {
    return section[position].getScore();
}

std::string Section_Basse::getDescCombinaison(unsigned int position) {
    return section[position].getDesc();
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

Section_Basse::~Section_Basse() {
    for(Figure * f :figures) {
        delete f;
    }
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
