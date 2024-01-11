#pragma once
#include <type_traits>
#include "../Figure.h"

template <typename T>
class Carre : public Figure
{
	const T& quatuor;
public:
	Carre(const T& quatuor) : quatuor(quatuor) {};

	int calculerPoints(const Lancer& lancer) const;
	int getIndForSave() const;
};

template<typename T>
int Carre<T>::calculerPoints(const Lancer& lancer) const
{
	if constexpr (std::is_base_of_v<Figure, T>)
		return quatuor.calculerPoints(lancer);
	return -1 /*Exception à faire*/;
}

template<typename T>
inline int Carre<T>::getIndForSave() const
{
	return 7;
}
