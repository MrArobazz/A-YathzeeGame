#include "Full.h"

int Full::calculerPoints(const Lancer& lancer) const
{
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    if ((desTries[0] == desTries[2] && desTries[3] == desTries[4]) ||
        (desTries[0] == desTries[1] && desTries[2] == desTries[4])) {
        return 25;
    }
    else {
        return 0;
    }
}
