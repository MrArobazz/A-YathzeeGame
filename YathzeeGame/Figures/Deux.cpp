#include "Deux.h"

int Deux::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 2)
            somme+=2;
    return somme;
}
