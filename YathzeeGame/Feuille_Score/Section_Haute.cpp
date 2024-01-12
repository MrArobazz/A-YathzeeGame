//
// Created by macine on 03/01/24.
//

#include "Section_Haute.h"

Section_Haute::Section_Haute() {
    std::shared_ptr<Figure> figure1 = std::make_shared<Un>();
    figures.push_back(figure1);
    std::shared_ptr<Figure> figure2 = std::make_shared<Deux>();
    figures.push_back(figure2);
    std::shared_ptr<Figure> figure3 = std::make_shared<Trois>();
    figures.push_back(figure3);
    std::shared_ptr<Figure> figure4 = std::make_shared<Quatre>();
    figures.push_back(figure4);
    std::shared_ptr<Figure> figure5 = std::make_shared<Cinq>();
    figures.push_back(figure5);
    std::shared_ptr<Figure> figure6 = std::make_shared<Six>();
    figures.push_back(figure6);

    section.push_back(Combinaison(figure1, "Somme des as obtenus :"));
    section.push_back(Combinaison(figure2 , "Somme des deux obtenus :"));
    section.push_back(Combinaison(figure3 , "Somme des trois obtenus :"));
    section.push_back(Combinaison(figure4 , "Somme des quatre obtenus :"));
    section.push_back(Combinaison(figure5 , "Somme des cinq obtenus :"));
    section.push_back(Combinaison(figure6 , "Somme des six obtenus :"));


}

void Section_Haute::setScore(Lancer &lancer , unsigned int position) {
        section[position].setScore(lancer);
        score_section += section[position].getScore();
        nb_combinaison_restante--;
    if(score_section >= 63 && !bonus)
    {
        score_section += 35;
        bonus = true;
    }
}

int Section_Haute::getScore() {
    return score_section;
}

int Section_Haute::getScorePosition(unsigned int position) {
    return section[position].getScore();
}


void Section_Haute::affiche() {
    for(int i = 0 ; i < section.size() ; ++i){
        std::cout<<1+i<<"-";
        section[i].affiche();
    }
    if(bonus){
        std::cout<<std::endl<<"BONUS  35 Points Acquis"<<std::endl<<std::endl;
    }
    std::cout<<"Score Section Haute : "<<score_section<<std::endl;

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

bool Section_Haute::is_full() {
    return nb_combinaison_restante == 0 ;
}

std::ostream& operator<<(std::ostream& out, const Section_Haute& sh)
{
    out << "Section_Haute:"
        << " " << sh.score_section
        << " " << sh.bonus
        << " " << sh.nb_combinaison_restante << std::endl;
    for (Combinaison comb : sh.section) {
        out << comb;
    };
    return out;
}

std::istream& operator>>(std::istream& input, Section_Haute& sh)
{
    std::string prefix;
    input >> prefix
        >> sh.score_section
        >> sh.bonus
        >> sh.nb_combinaison_restante;
    for (Combinaison& comb : sh.section)
        input >> comb;
    return input;
}
