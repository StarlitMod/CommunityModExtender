#include "CVector.h"

// Returns length of vector
float CVector::Magnitude()
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

float CVector::Magnitude2D()
{
	return sqrt(this->x * this->x + this->y * this->y);
}
