#pragma once
#include <algorithm>
#include "../Figure.h"
class Full : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
};

