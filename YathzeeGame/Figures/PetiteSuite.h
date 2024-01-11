#pragma once
#include <algorithm>
#include "../Figure.h"
class PetiteSuite : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
	int getIndForSave() const;
};