// play.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Lancer.h"
#include "Figures/Brelan.h"
#include "Figures/Carre.h"
#include "Figures/Chance.h"
#include "Figures/Cinq.h"
#include "Figures/Deux.h"
#include "Figures/Full.h"
#include "Figures/GrandeSuite.h"
#include "Figures/PetiteSuite.h"
#include "Figures/Quatre.h"
#include "Figures/Six.h"
#include "Figures/Trois.h"
#include "Figures/Un.h"
#include "Figures/Yams.h"

using namespace std;
int main()
{
	srand((unsigned int)time(nullptr));

	Lancer l;
	l.rollDices();
	for (const auto& de : l.getDices()) {
		cout << de.getValue() << " ";
	}
	cout << endl;
	Full f;
	cout << f.calculerPoints(l);

}