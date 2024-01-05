#include "Trois.h"

int Trois::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 3)
            somme+=3;
    return somme;
}
