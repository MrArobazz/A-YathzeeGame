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
		void roll();
		bool isLocked() const { return locked; };
		int getValue() const { return num; };
	};

	std::vector<De> des;
public:
	Lancer();
	void rollDices();
	void lockOrUnlockDice(const int& ind);
	const std::vector<De>& getDices() const { return des; };
};

