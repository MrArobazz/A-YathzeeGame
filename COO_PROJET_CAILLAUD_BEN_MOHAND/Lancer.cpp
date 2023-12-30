#include "Lancer.h"

using namespace std;

void Lancer::De::roll()
{
	if (!locked)
		num = rand() % 6 + 1;
}

Lancer::Lancer() : des{}
{
	for (int i = 0; i < 5; i++) {
		De d;
		des.push_back(d);
	}
}

void Lancer::rollDices()
{
	for (De d : des)
		d.roll();

}

void Lancer::lockOrUnlockDice(const int& ind)
{
	De& de = des.at(ind);
	de.lockOrUnlock(!de.isLocked());
}
