#include "Chance.h"

int Chance::calculerPoints(const Lancer& lancer) const
{
	return lancer.a + lancer.b + lancer.c + lancer.d + lancer.e;
}
