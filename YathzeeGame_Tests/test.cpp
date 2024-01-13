#include "pch.h"
#include <array>
#include "Lancer.h"
#include "Feuille_Score/Feuille_de_score.h"

TEST(TestLancer, LancerNormal) {
    Lancer l;
    std::array<int, 5> fstDes{};
    std::array<int, 5> scdDes{};
    int ind = 0;
    for (const auto& de : l.getDices()) {
        fstDes[ind] = de.getValue();
        ind++;
    }
    ind = 0;
    l.rollDices();
    for (const auto& de : l.getDices()) {
        scdDes[ind] = de.getValue();
        ind++;
    }
    ASSERT_FALSE(fstDes == scdDes);
    // voir si on doit pas refaire une deuxième fois en cas d'un mauvais tirage
}

TEST(TestLancer, LancerLock) {
    Lancer l;
    std::array<int, 5> fstDes{};
    std::array<int, 5> scdDes{};

    int ind = 0;
    for (const auto& de : l.getDices()) {
        fstDes[ind] = de.getValue();
        ind++;
    }
    l.lockOrUnlockDice(0);
    l.lockOrUnlockDice(2);
    l.lockOrUnlockDice(4);
    ind = 0;
    for (const auto& de : l.getDices()) {
        scdDes[ind] = de.getValue();
        ind++;
    }
    ASSERT_TRUE(fstDes[0] == scdDes[0] && fstDes[2] == scdDes[2] && fstDes[4] == scdDes[4]);
}

TEST(TestScore, AllDigitsScore) {
    Lancer l;
    Feuille_de_score f(1);
    for (int value = 1; value <= 6; value++) {
        for (int de = 0; de < 5; de++) {
            l.setValueForADice(value, de);
        }
        f.setScore(l, value - 1);
    }
    ASSERT_EQ(f.getScore(), 140);
}

TEST(TestScore, ActivateBonus) {
    Lancer l;
    Feuille_de_score f(1);
    for (int de = 0; de < 5; de++) {
        l.setValueForADice(6, de);
    }
    f.setScore(l, 5); // Reconnait les six (5*6 -> 30)
    for (int de = 0; de < 5; de++) {
        l.setValueForADice(5, de);
    }
    f.setScore(l, 4); // Reconnait les cinq (5*5 -> 55)
    l.setValueForADice(4, 0);
    f.setScore(l, 3); // Reconnait les quatre (1*4 -> 59)
    l.setValueForADice(3, 0);
    f.setScore(l, 2); // Reconnait les trois (1*3 -> 62)
    ASSERT_EQ(f.getScore(), 62);
    l.setValueForADice(1, 0);
    f.setScore(l, 0); // Reconnait les un (1*1 -> 63)
    ASSERT_EQ(f.getScore(), 98);
}

TEST(TestScore, BrelanScore) {
    Lancer l;
    for (int value = 1; value <= 6; value++) {
        Feuille_de_score f(1);
        for (int de = 0; de < 5; de++) {
            l.setValueForADice(value, de);
        }
        f.setScore(l, 6);
        ASSERT_EQ(f.getScore(), value * 3);
    }
}

TEST(TestScore, CarreScore) {
    Lancer l;
    for (int value = 1; value <= 6; value++) {
        Feuille_de_score f(1);
        for (int de = 0; de < 5; de++) {
            l.setValueForADice(value, de);
        }
        f.setScore(l, 7);
        ASSERT_EQ(f.getScore(), value * 4);
    }
}

TEST(TestScore, FullScore) {
    Lancer l;
    Feuille_de_score f(1);
    l.setValueForADice(1, 0);
    l.setValueForADice(2, 1);
    l.setValueForADice(1, 2);
    l.setValueForADice(1, 3);
    l.setValueForADice(2, 4);
    f.setScore(l, 8);
    ASSERT_EQ(f.getScore(), 25);
}

TEST(TestScore, PetiteSuiteScore) {
    // On a beaucoup galéré sur la petite suite donc je mets tous les tests que j'ai pu faire pour résoudre les pb que j'ai eu
    Lancer l;
    std::vector<std::vector<int>> testsOK{
        { 1,2,3,4,6 },
        { 5,4,3,2,1 },
        { 2,3,4,5,6 },
        { 1,1,2,3,4 },
        { 1,2,3,4,4 }
    };

    for (const std::vector<int>& test : testsOK) {
        Feuille_de_score f(1);
        for (int i = 0; i < 5; i++)
            l.setValueForADice(test.at(i), i);
        f.setScore(l, 9);
        ASSERT_EQ(f.getScore(), 30); // << "Teste avec les des suivants : " << for (const int& val : test) { val;};
        if (f.getScore() != 30) {
            std::cout << "Test avec les des suivants :";
            for (const int& val : test) {
                std::cout << " " << val;
            }
            std::cout << std::endl;
        }
    }

    auto rng = std::default_random_engine{};
    for (std::vector<int>& test : testsOK)
        std::shuffle(test.begin(), test.end(), rng);

    for (const std::vector<int>& test : testsOK) {
        Feuille_de_score f(1);
        for (int i = 0; i < 5; i++)
            l.setValueForADice(test.at(i), i);
        f.setScore(l, 9);
        ASSERT_EQ(f.getScore(), 30);
        if (f.getScore() != 30) {
            std::cout << "Test avec les des suivants :";
            for (const int& val : test) {
                std::cout << " " << val;
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<int>> testsNotOK{
        { 1,2,2,3,5 },
        { 1,2,3,5,6 },
        { 1,2,3,5,5 }
    };

    for (const std::vector<int>& test : testsNotOK) {
        Feuille_de_score f(1);
        for (int i = 0; i < 5; i++)
            l.setValueForADice(test.at(i), i);
        f.setScore(l, 9);
        ASSERT_EQ(f.getScore(), 0);
        if (f.getScore() != 0) {
            std::cout << "Test avec les des suivants :";
            for (const int& val : test) {
                std::cout << " " << val;
            }
            std::cout << std::endl;
        }
    }
}

TEST(TestScore, GrandeSuiteScore) {
    Lancer l;
    std::vector<std::vector<int>> testsOK{
        { 1,2,3,4,5 },
        { 5,4,3,2,1 },
        { 2,3,4,5,6 },
    };

    for (const std::vector<int>& test : testsOK) {
        Feuille_de_score f(1);
        for (int i = 0; i < 5; i++)
            l.setValueForADice(test.at(i), i);
        f.setScore(l, 10);
        ASSERT_EQ(f.getScore(), 40);
        if (f.getScore() != 40) {
            std::cout << "Test avec les des suivants :";
            for (const int& val : test) {
                std::cout << " " << val;
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<int>> testsNotOK{
        { 1,2,2,3,5 },
        { 1,1,2,3,4 },
        { 1,2,3,4,6 }
    };

    for (const std::vector<int>& test : testsNotOK) {
        Feuille_de_score f(1);
        for (int i = 0; i < 5; i++)
            l.setValueForADice(test.at(i), i);
        f.setScore(l, 10);
        ASSERT_EQ(f.getScore(), 0);
        if (f.getScore() != 0) {
            std::cout << "Test avec les des suivants :";
            for (const int& val : test) {
                std::cout << " " << val;
            }
            std::cout << std::endl;
        }
    }
}

TEST(TestScore, YamsScore) {
    Lancer l;
    for (int value = 1; value <= 6; value++) {
        Feuille_de_score f(1);
        for (int de = 0; de < 5; de++) {
            l.setValueForADice(value, de);
        }
        f.setScore(l, 11);
        ASSERT_EQ(f.getScore(), 50);
    }
}

TEST(TestScore, ChanceScore) {
    Lancer l;
    int res = 0;
    for (const auto& de : l.getDices()) {
        res += de.getValue();
    }
    Feuille_de_score f(1);
    f.setScore(l, 12);
    ASSERT_EQ(f.getScore(), res);
}

TEST(TestScore, MaxReachable) {
    Lancer l;
    Feuille_de_score f(1);
    std::vector<std::vector<int>> inputs{
        { 6,6,6,1,1 },
        { 6,6,6,6,1 },
        { 1,1,1,2,2 },
        { 1,2,3,4,6 },
        { 1,2,3,4,5 },
        { 1,1,1,1,1 },
        { 6,6,6,6,6 }
    };
    int fig = 6;
    for (const std::vector<int>& input : inputs) {
        for (int i = 0; i < 5; i++)
            l.setValueForADice(input.at(i), i);
        f.setScore(l, fig);
        fig++;
    }
    ASSERT_EQ(f.getScore(), 317);
}

TEST(TestScore, ActivateYams) {
    Lancer l;
    Feuille_de_score f(1);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(6, i);
    f.setScore(l, 11);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(5, i);
    f.setScore(l, 12);
    ASSERT_EQ(f.getScore(), 175);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(4, i);
    f.setScore(l, 7);
    ASSERT_EQ(f.getScore(), 191);
}

TEST(TestScore, NotActivateYams) {
    Lancer l;
    Feuille_de_score f(1);
    l.setValueForADice(1, 0);
    l.setValueForADice(2, 1);
    f.setScore(l, 11);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(5, i);
    f.setScore(l, 12);
    ASSERT_EQ(f.getScore(), 25);
}

TEST(TestScore, PerfectGame) {
    Lancer l;
    Feuille_de_score f(1);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(6, i);
    f.setScore(l, 11);
    f.setScore(l, 5);
    f.setScore(l, 6);
    l.setValueForADice(6, 3);
    l.setValueForADice(6, 4);
    f.setScore(l, 7);
    l.setValueForADice(6, 4);
    f.setScore(l, 12);
    l.setValueForADice(5, 3);
    l.setValueForADice(5, 4);
    f.setScore(l, 8);
    for (int i = 0; i < 5; i++)
        l.setValueForADice(i+1, i);
    f.setScore(l, 9);
    f.setScore(l, 10);
    for (int val = 1; val <= 5; val++) {
        for (int de = 0; de < 5; de++)
            l.setValueForADice(val, de);
        f.setScore(l, val - 1);
    }
    ASSERT_EQ(f.getScore(), 457);
}