#include "Full.h"

int Full::calculerPoints(const Lancer& lancer) const
{
    int desTries[5]{};
    desTries[0] = lancer.a;
    desTries[1] = lancer.b;
    desTries[2] = lancer.c;
    desTries[3] = lancer.d;
    desTries[4] = lancer.e;
    std::sort(std::begin(desTries), std::end(desTries));

    if ((desTries[0] == desTries[2] && desTries[3] == desTries[4]) ||
        (desTries[0] == desTries[1] && desTries[2] == desTries[4])) {
        return 25;
    }
    else {
        return 0;
    }
}
