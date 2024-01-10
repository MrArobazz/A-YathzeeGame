#pragma once
#include <vector>
#include <iostream>

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
		void setValue(const unsigned int& n) { num = n; };
        void unlock();
	};

	std::vector<De> des;
public:
	Lancer();
	void rollDices();
	void lockOrUnlockDice(const int& ind);
	const std::vector<De>& getDices() const { return des; };
	std::vector<De>& getDices() { return des; };
    void remiseAzeroDe();
	void setValueForADice(const unsigned int& value, const unsigned int& pos);
};

