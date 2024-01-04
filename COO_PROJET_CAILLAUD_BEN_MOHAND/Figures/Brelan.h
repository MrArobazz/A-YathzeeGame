#pragma once
#include <type_traits>
#include "../Figure.h"

template <typename T>
class Brelan : public Figure
{
	const T& trio;
public:
	Brelan(const T& trio) : trio(trio) {};

	int calculerPoints(const Lancer& lancer) const;
};

template<typename T>
int Brelan<T>::calculerPoints(const Lancer& lancer) const
{
	if constexpr (std::is_base_of_v<Figure, T>)
		return trio.calculerPoints(lancer);
	return -1 /*Exception � faire*/;
}
