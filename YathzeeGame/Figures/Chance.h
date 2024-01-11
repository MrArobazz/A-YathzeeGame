#pragma once
#include <algorithm>
#include "../Figure.h"
class Chance : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
	int getIndForSave() const;
};