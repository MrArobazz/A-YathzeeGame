//
// Created by macine on 03/01/24.
//

#pragma once
#include "Combinaison.h"

class Section_Haute {

    private:
        std::vector<std::shared_ptr<Figure>> figures;
        std::vector<Combinaison> section;
        int score_section = 0;
        bool bonus = false;
        int nb_combinaison_restante = 6;
    public:
        Section_Haute();


        void setScore(Lancer & lancer , unsigned int position);
        int getScore();
        int getScorePosition(unsigned int position);
        void affiche();

        void setPreviewScore(Lancer& lancer, unsigned int position);
        void resetPreviewScores();
        void affichePreview(unsigned int position);

        bool is_full();

        friend std::ostream& operator<<(std::ostream& out, const Section_Haute& sh);
        friend std::istream& operator>>(std::istream& input, Section_Haute& sh);
};
