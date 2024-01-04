//
// Created by macine on 03/01/24.
//

#include "Section_Basse.h"

Section_Basse::Section_Basse() {
    Figure * f1;
    Figure * f2;
    Figure * f3 = new Full();
    Figure * f4 = new PetiteSuite();
    Figure * f5 = new GrandeSuite();
    Figure * f6 = new Yams();
    Figure * f7 = new Chance();


    section.push_back(Combinaison(*f1 , "Brelan Somme des 3 dés :"));
    section.push_back(Combinaison(*f2 , "Carré Somme des 3 dés :"));
    section.push_back(Combinaison(*f3 , "Full 25 Points :"));
    section.push_back(Combinaison(*f4 , "Petite Suite 30 Points :"));
    section.push_back(Combinaison(*f5 , "Grande Suite 40 Points : "));
    section.push_back(Combinaison(*f6 , "Yams  50 Points :"));
    section.push_back(Combinaison(*f7 , "Chance Somme des 5 dés :"));
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
        std::cout<<7+i<<" ";
        section[i].affiche();
    }
}