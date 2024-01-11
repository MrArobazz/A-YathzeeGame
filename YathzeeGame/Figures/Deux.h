#pragma once
#include "../Figure.h"
class Deux : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
	int getIndForSave() const;
};

