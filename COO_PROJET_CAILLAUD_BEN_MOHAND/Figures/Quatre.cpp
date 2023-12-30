#include "Quatre.h"

int Quatre::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 4) somme += 4;
    if (lancer.b == 4) somme += 4;
    if (lancer.c == 4) somme += 4;
    if (lancer.d == 4) somme += 4;
    if (lancer.e == 4) somme += 4;
    return somme;
}
