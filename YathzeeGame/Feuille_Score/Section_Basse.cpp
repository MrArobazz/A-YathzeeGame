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

    section.push_back(Combinaison(figure1 , "Brelan (somme des 3 des) :", 9));
    section.push_back(Combinaison(figure2 , "Carre (somme des 4 des) :", 12));
    section.push_back(Combinaison(figure3 , "Full :", 25));
    section.push_back(Combinaison(figure4 , "Petite Suite :", 30));
    section.push_back(Combinaison(figure5 , "Grande Suite : ", 40));
    section.push_back(Combinaison(figure6 , "Yams :", 50));
    section.push_back(Combinaison(figure7 , "Chance (Somme des 5 des) :", 15));
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

    /*Pour fix des lancers qui ont + de 3 d�s du brelan*/
    int cpt_brelan = 0;
    for (int i = 0; i < 5;i++) {
        if (lancer.getDices().at(i).getValue() == brelan)
            cpt_brelan++;
        if (cpt_brelan > 3) {
            lancer.setValueForADice(brelan + 1, i);
            cpt_brelan--;
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

    /*Pour fix des lancers qui ont + de 4 d�s du carr�*/
    int cpt_carre = 0;
    for (int i = 0; i < 5;i++) {
        if (lancer.getDices().at(i).getValue() == carre)
            cpt_carre++;
        if (cpt_carre > 4) {
            lancer.setValueForADice(carre + 1, i);
            cpt_carre--;
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
    std::cout << "Score Section Basse : " << score_section << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Section_Basse& sb)
{
    out << "Section_Basse:"
        << " " << sb.score_section
        << " " << sb.locked
        << " " << sb.bonus << std::endl;
    for (Combinaison comb : sb.section) {
        out << comb;
    };
    return out;
}

std::istream& operator>>(std::istream& input, Section_Basse& sb)
{
    std::string prefix;
    input >> prefix
        >> sb.score_section
        >> sb.locked
        >> sb.bonus;
    for (Combinaison& comb : sb.section)
        input >> comb;
    return input;
}

void Section_Basse::get_combinaison(std::vector<position> &pos) {
    for (int i = 0 ;  i < section.size() ; ++i){
        if (section[i].get_preview_score() != -1)
        {
            pos.push_back(position(i+6,section[i].get_preview_score()));
        }
    }
}

