//
// Created by macine on 03/01/24.
//

#ifndef COO_PROJET_CAILLAUD_BEN_MOHAND_SECTION_HAUTE_H
#define COO_PROJET_CAILLAUD_BEN_MOHAND_SECTION_HAUTE_H

#include "Combinaison.h"

class Section_Haute {

    private:
        std::vector<Combinaison> section;
        int score_section = 0;
        int bonus = 35;
    public:
        Section_Haute();
        void setScore(Lancer & lancer , unsigned int position);
        int getScore();
        int getScorePosition(unsigned int position);
        std::string getDescCombinaison(unsigned int position);
        void affiche();

};


#endif //COO_PROJET_CAILLAUD_BEN_MOHAND_SECTION_HAUTE_H
