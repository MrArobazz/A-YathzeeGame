#include "Chance.h"

int Chance::calculerPoints(const Lancer& lancer) const
{
	int somme = 0;
    for (const auto& de : lancer.getDices())
        somme += de.getValue();
    return somme;
}
