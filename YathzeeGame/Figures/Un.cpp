#include "Un.h"

int Un::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    for (const auto& de : lancer.getDices())
        if (de.getValue() == 1)
            somme++;
    return somme;
}

int Un::getIndForSave() const
{
    return 0;
}
