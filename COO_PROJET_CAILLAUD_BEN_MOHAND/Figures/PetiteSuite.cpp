#include "PetiteSuite.h"

int PetiteSuite::calculerPoints(const Lancer& lancer) const
{
    int desTries[5]{};
    desTries[0] = lancer.a;
    desTries[1] = lancer.b;
    desTries[2] = lancer.c;
    desTries[3] = lancer.d;
    desTries[4] = lancer.e;
    std::sort(std::begin(desTries), std::end(desTries));

    for (int i = 0; i < 2; ++i) {
        if (desTries[i] + 1 != desTries[i + 1]) {
            return 0;
        }
    }

    return 30;
}
