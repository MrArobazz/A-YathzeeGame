#include "Lancer.h"

using namespace std;

int Lancer::De::roll()
{
	if (!locked)
		num = rand() % 6 + 1;
	return num;
}

Lancer::Lancer()
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

void Lancer::lockOrUnlockDice(const int& ind, const bool& toLock)
{
	des.at(ind).lockOrUnlock(toLock);
}
