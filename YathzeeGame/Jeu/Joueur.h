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
                                     " Qui je suis ?Ton pire cauchemar.","Il est aussi con que ce qu'il est moche","T'es mauvais Jack",
                                     "Tu es doué petit, très doué. Mais tant que je serai dans le métier, tu ne seras toujours que le second","Dans le langage des filles, ça s'appelle un vent. fais gaffe, tu vas t'enrhumer."
    ,"Je sens que je vais conclure","Tu la sens ma grosse intelligence !","Ici c’est moi qui fait la loi alors faites pas chier."};
    std::vector<std::string> Hakim{"Dès que vous avez validé votre master, on a le même niveau","je suis pas un compilateur g++ sinon je serais Hakim ++","moi en graphique j'étais moche",
                                   "Il y a 2 personnes qui me font peur sur cette planète, ma mère... Et ma femme.",
                                   "Bravo, t'a fait fort","Vous êtes meilleurs que moi en java, c'est pas moi qui le dit c'est l'Europe ! ",
                                   "Je suis comme les machines de la fac monsieur, il me faut du temps pour démarrer     C'est ce qu'elle t'a dit hier soir ?",
                                   "C'est parce que t'es pas venu en cours ce matin, t'es pas chaud. Regarde lui il est chaud. Il fait de la merde mais il est chaud"
    ,"Oh la la mais comment je suis bon !","Dans la logique actuellement, tu n'as pas de logique !"};





};
