#include "Un.h"

int Un::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 1) somme++;
    if (lancer.b == 1) somme++;
    if (lancer.c == 1) somme++;
    if (lancer.d == 1) somme++;
    if (lancer.e == 1) somme++;
    return somme;
}
