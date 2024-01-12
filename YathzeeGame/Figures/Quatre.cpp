#include "Quatre.h"

int Quatre::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 4)
            somme += 4;
    return somme;
}

int Quatre::getIndForSave() const
{
    return 3;
}
