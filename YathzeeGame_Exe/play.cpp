// play.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <cstdlib>
#include <ctime>


#include "Jeu/Jeu.h"


using namespace std;
int main()
{
    srand((unsigned int)time(nullptr));
    Jeu J;
    J.LancerJeu();
}