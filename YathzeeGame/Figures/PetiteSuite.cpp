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

    for (int i = 0; i <= 1; ++i) {
        int count = 1;
        int max_to_go = 3 + i;
        for (int j = i; j < max_to_go; ++j) {
            if (desTries[j + 1] - desTries[j] == 1)
                count++;
            else if (desTries[j + 1] != desTries[j]) {
                count = 1;
                break;
            }
            else
                max_to_go++;
        }

        if (count >= 4)
            return 30;
    };

    return 0;
}