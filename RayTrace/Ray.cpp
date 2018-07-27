#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vect3 & _origin, const Vect3 & _direction)
	:
	origin(_origin),
	direction(_direction)
{
}

Ray::Ray(const Ray & right)
	:
	origin(right.origin),
	direction(right.direction)
{
}

Ray::~Ray()
{
}

Ray & Ray::operator=(const Ray & right)
{
	// TODO: �ڴ˴����� return ���
	this->origin = right.origin;
	this->direction = right.direction;
	return *this;
}
