// play.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <cstdlib>
#include <ctime>


#include "Jeu/Jeu.h"


using namespace std;
int main()
{
	srand(time(nullptr));
    Jeu J;
    J.LancerJeu();
}