#pragma once
#include "Lancer.h"

class Figure
{
public:
	virtual int calculerPoints(const Lancer& lancer) const = 0;
};

