#include "Six.h"

int Six::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 6)
            somme += 6;
    return somme;
}
