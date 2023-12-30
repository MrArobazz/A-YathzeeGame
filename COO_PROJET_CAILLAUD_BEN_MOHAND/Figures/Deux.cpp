#include "Deux.h"

int Deux::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 2) somme += 2;
    if (lancer.b == 2) somme += 2;
    if (lancer.c == 2) somme += 2;
    if (lancer.d == 2) somme += 2;
    if (lancer.e == 2) somme += 2;
    return somme;
}
