#include "GrandeSuite.h"

int GrandeSuite::calculerPoints(const Lancer& lancer) const
{

    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    for (int i = 0; i < 4; ++i) {
        if (desTries[i] + 1 != desTries[i + 1]) {
            return 0;
        }
    }

    return 40;
}

int GrandeSuite::getIndForSave() const
{
    return 10;
}
