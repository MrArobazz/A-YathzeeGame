#include "PetiteSuite.h"

int PetiteSuite::calculerPoints(const Lancer& lancer) const
{

    int desTries[5]{};
    int ind = 0;
    for (const auto& de : lancer.getDices()) {
        desTries[ind] = de.getValue();
        ind++;
    }
    std::sort(std::begin(desTries), std::end(desTries));

    int count = 0;
    for (int i = 0; i <= 1; ++i) {
        for (int j = i; j < 3 + i; ++j) {
            if (desTries[j] + 1 == desTries[j + 1])
                count++;
            else {
                count = 0;
                break;
            }
        }

        if (count >= 3)
            return 30;
    };

    return 0;
}
