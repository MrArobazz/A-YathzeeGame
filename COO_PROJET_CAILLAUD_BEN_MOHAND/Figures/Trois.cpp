#include "Trois.h"

int Trois::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 3) somme += 3;
    if (lancer.b == 3) somme += 3;
    if (lancer.c == 3) somme += 3;
    if (lancer.d == 3) somme += 3;
    if (lancer.e == 3) somme += 3;
    return somme;
}
