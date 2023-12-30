#include "Six.h"

int Six::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 6) somme += 6;
    if (lancer.b == 6) somme += 6;
    if (lancer.c == 6) somme += 6;
    if (lancer.d == 6) somme += 6;
    if (lancer.e == 6) somme += 6;
    return somme;
}
