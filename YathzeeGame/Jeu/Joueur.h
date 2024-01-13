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
    std::string getName();
    void affiche();

    int get_type();

    bool isok(Lancer & lancer);

    std::string getCitation();

    void affichePreview(Lancer& lancer);


    int get_pos_bot(Lancer & lancer);
    int getScoreLancer(Lancer & lancer);

    bool is_human() const;

    ~Joueur();

    friend std::ostream& operator<<(std::ostream& out, const Joueur& j);
    friend std::istream& operator>>(std::istream& input, Joueur& j);



































































































































































private:
    std::vector<std::string> Nicolas{"Parfois on ne gagne pas sauf Hakim, lui, il gagne toujours.","Comment on torture un robot? J'en sais rien moi. Peut-etre en insultant sa carte-mere ou en se moquant de la taille de son disque dur.","Tu joues comme un bot mais niveau M1, un nul en gros.","T'as pas une gueule de porte-bonheur.",
                                     "Qui suis-je? Ton pire cauchemar.","Il est aussi con que ce qu'il est moche.","T'es mauvais Jack. C'est la piquette!",
                                     "Tu es doue petit, tres doue. Mais tant que je serai dans le metier, tu ne seras toujours que le second"
    ,"Je sens que je vais conclure.","Tu la sens ma grosse intelligence!","Ici cest moi qui fait la loi alors faites pas chier."};
    std::vector<std::string> Hakim{"Je suis moins expert que vous en Yathzee", "Hop tu fais petite suite into carre et c'est gagne, c'est niveau 1.", "Si vous avez un probleme, vous consultez mon collegue Nicolas.",
                                   "Quand vous m'aurez battu, vous pourrez vous considerer aussi fort que Nicolas","Je suis pas un joueur pro sinon je serais HakimGPT.",
                                   "Il y a 2 personnes qui me font peur sur cette planete, ma carte-mère... Et ma femme.",
                                   "Bravo, t'as fait fort.", "Vous etes meilleurs que moi en Yathzee, c'est pas moi qui le dit, c'est l'Europe!",
                                   "C'est parce que t'es pas venu en cours ce matin, t'es pas chaud. Regarde lui il est chaud. Il fait de la merde mais il est chaud."
    ,"Oh la la mais comment je suis bon !","Dans la logique actuellement, tu n'as pas de logique !"};





};
