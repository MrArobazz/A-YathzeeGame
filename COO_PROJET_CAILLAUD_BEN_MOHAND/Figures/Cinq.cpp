#include "Cinq.h"

int Cinq::calculerPoints(const Lancer& lancer) const
{
    int somme = 0;
    if (lancer.a == 5) somme+= 5;
    if (lancer.b == 5) somme+= 5;
    if (lancer.c == 5) somme+= 5;
    if (lancer.d == 5) somme+= 5;
    if (lancer.e == 5) somme+= 5;
    return somme;
}
