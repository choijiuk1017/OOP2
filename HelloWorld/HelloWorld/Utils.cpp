#include "Utils.h"

Position<int> Position<int>::InvalidPosition { INT_MAX, INT_MAX };
Position<float> Position<float>::InvalidPosition{ FLT_MAX, FLT_MAX };

template<typename T>
bool Position<T>::operator==(const Position<T>& other)
{
	return this->x == other.x && this->y == other.y;
}

template<>
bool Position<float>::operator==(const Position<float>& other)
{
	bool result = static_cast<float>((*this - other).magnitude() )< 0.5f;
	if (result == true) {
		if (other.x == FLT_MAX && other.y == FLT_MAX) return result;
		*this = other;
	}	
	return result;
}