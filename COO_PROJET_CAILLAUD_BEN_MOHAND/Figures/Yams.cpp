#include "Yams.h"

int Yams::calculerPoints(const Lancer& lancer) const
{
    int desTries[5]{};
    desTries[0] = lancer.a;
    desTries[1] = lancer.b;
    desTries[2] = lancer.c;
    desTries[3] = lancer.d;
    desTries[4] = lancer.e;
    std::sort(std::begin(desTries), std::end(desTries));

    if (desTries[0] == desTries[4])
        return 50;
    return 0;
}
