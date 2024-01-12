#pragma once
#include <algorithm>
#include "../Figure.h"
class Yams : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
};