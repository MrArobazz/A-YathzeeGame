#pragma once
#include "../Figure.h"

template <typename T>
class Brelan : public Figure
{
	T& trio;
public:
	int calculerPoints(const Lancer& lancer) const;
};

template<typename T>
int Brelan<T>::calculerPoints(const Lancer& lancer) const
{
	return -1 /*Exception à faire*/;
}

template<>
inline int Brelan<Figure>::calculerPoints(const Lancer& lancer) const
{
	
}