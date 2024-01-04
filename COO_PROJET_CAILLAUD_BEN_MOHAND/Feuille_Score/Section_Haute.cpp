//
// Created by macine on 03/01/24.
//

#include "Section_Haute.h"

Section_Haute::Section_Haute() {
    Figure * f1 = new Un();
    Figure * f2 = new Deux();
    Figure * f3 = new Trois();
    Figure * f4 = new Quatre();
    Figure * f5 = new Cinq();
    Figure * f6 = new Six();


    section.push_back(Combinaison(*f1 , "Somme des as obtenus :"));
    section.push_back(Combinaison(*f2 , "Somme des deux obtenus :"));
    section.push_back(Combinaison(*f3 , "Somme des trois obtenus :"));
    section.push_back(Combinaison(*f4 , "Somme des quatre obtenus :"));
    section.push_back(Combinaison(*f5 , "Somme des cinq obtenus :"));
    section.push_back(Combinaison(*f6 , "Somme des six obtenus :"));


}


void Section_Haute::setScore(Lancer &lancer , unsigned int position) {
        section[position].setScore(lancer);
        score_section += section[position].getScore();
}

int Section_Haute::getScore() {
    return score_section;
}

int Section_Haute::getScorePosition(unsigned int position) {
    return section[position].getScore();
}

std::string Section_Haute::getDescCombinaison(unsigned int position) {
    return section[position].getDesc();
}

void Section_Haute::affiche() {
    for(int i = 0 ; i < section.size() ; ++i){
        std::cout<<1+i<<" ";
        section[i].affiche();
    }
}