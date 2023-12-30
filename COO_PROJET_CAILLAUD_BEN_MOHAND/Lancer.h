#pragma once
#include <vector>

class Lancer
{
	class De
	{
		unsigned int num;
		bool locked;
	public:
		De() : num(std::rand() % 6 + 1), locked(false) {};
		void lockOrUnlock(const bool& toLock) { locked = toLock; };
		int roll();
	};

	std::vector<De> des;
public:
	Lancer() : des{} {};
	void rollDices();
	void lockOrUnlockDice(const int& ind, const bool& toLock);
};

