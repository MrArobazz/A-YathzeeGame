//
// Created by macine on 03/01/24.
//

#include "Section_Haute.h"

Section_Haute::Section_Haute() {
    Figure * f1 = new Un();
    figures.push_back(f1);
    Figure * f2 = new Deux();
    figures.push_back(f2);
    Figure * f3 = new Trois();
    figures.push_back(f3);
    Figure * f4 = new Quatre();
    figures.push_back(f4);
    Figure * f5 = new Cinq();
    figures.push_back(f5);
    Figure * f6 = new Six();
    figures.push_back(f6);


    section.push_back(Combinaison(f1 , "Somme des as obtenus :"));
    section.push_back(Combinaison(f2 , "Somme des deux obtenus :"));
    section.push_back(Combinaison(f3 , "Somme des trois obtenus :"));
    section.push_back(Combinaison(f4 , "Somme des quatre obtenus :"));
    section.push_back(Combinaison(f5 , "Somme des cinq obtenus :"));
    section.push_back(Combinaison(f6 , "Somme des six obtenus :"));


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
        std::cout<<1+i<<"-";
        section[i].affiche();
    }
}

void Section_Haute::setPreviewScore(Lancer& lancer, unsigned int position)
{
    section[position].setPreviewScore(lancer);
}

void Section_Haute::resetPreviewScores()
{
    for (Combinaison fig : section)
        fig.resetPreviewScore();
}

void Section_Haute::affichePreview(unsigned int position)
{
    std::cout << 1 + position << "-";
    section[position].affichePreview();
}

Section_Haute::~Section_Haute() {
    for(Figure * f :figures)
    {
        delete f;
    }
}
