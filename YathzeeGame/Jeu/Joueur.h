//
// Created by macine on 04/01/24.
//

#pragma once
#include "../Feuille_Score/Feuille_de_score.h"

class Joueur {
private:
    Feuille_de_score feuille_score;
    std::string name;
    unsigned int mode_jeu;
    bool is_humain;
    unsigned int type_joueur;
    int max(const std::vector<position> &pos);
    int maxhakim(const std::vector<position> &pos);

public:
    Joueur(unsigned int mode,unsigned int bot ,bool human = true);
    Joueur() : feuille_score(), name("MIIIIICHEEEEEEL"), mode_jeu(1), is_humain(true), type_joueur(0){}; // pour eviter le usage du constructeur au dessus (qui utilise cin) pour la save

    bool setScore(Lancer & lancer , unsigned int position);
    void setScore(Lancer & lancer);
    int getScore();
    std::string getName();
    void affiche();

    std::string getCitation();

    void affichePreview(Lancer& lancer);


    int get_pos_bot(Lancer & lancer);
    int getScoreLancer(Lancer & lancer);

    bool is_human() const;

    ~Joueur();

    friend std::ostream& operator<<(std::ostream& out, const Joueur& j);
    friend std::istream& operator>>(std::istream& input, Joueur& j);



































































































































































private:
    std::vector<std::string> Nicolas{"Parfois on ne gagne pas,c'est l’adversaire qui perd","Comment on torture un robot ?J'en sais rien moi. Peut - être en insultant sa carte-mère ou en se moquant de la taille de son disque dur.","Tu frappes comme un végétarien.","T'as pas une gueule de porte-bonheur",
                                     " Qui je suis ?Ton pire cauchemar.","Il est aussi con que ce qu'il est moche"};
    std::vector<std::string> Hakim{"test"};





};
