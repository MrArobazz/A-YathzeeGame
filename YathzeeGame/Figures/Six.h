#pragma once
#include "../Figure.h"
class Six : public Figure
{
public:
	int calculerPoints(const Lancer& lancer) const;
	int getIndForSave() const;
};
