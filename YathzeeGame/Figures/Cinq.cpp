#include "Cinq.h"

int Cinq::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 5)
            somme += 5;
    return somme;
}
