#pragma once
#include "Lancer.h"

class Figure
{
public:
    Figure(){};
    Figure(const Figure & fig){};
	virtual int calculerPoints(const Lancer& lancer) const = 0;
    virtual int getIndForSave() const = 0;
};

