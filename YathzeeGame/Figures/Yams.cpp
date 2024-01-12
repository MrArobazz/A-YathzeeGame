#include "Yams.h"

int Yams::calculerPoints(const Lancer& lancer) const
{
    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    if (desTries[0] == desTries[4])
        return 50;
    return 0;
}