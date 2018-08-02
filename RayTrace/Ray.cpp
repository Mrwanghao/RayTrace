#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vect3 & _origin, const Vect3 & _direction)
	:
	origin(_origin),
	direction(_direction)
{
	direction.Normalize();
}

Ray::Ray(const Ray & right)
	:
	origin(right.origin),
	direction(right.direction)
{
	direction.Normalize();
}

Ray::~Ray()
{
}

Ray & Ray::operator=(const Ray & right)
{
	this->origin = right.origin;
	this->direction = right.direction;
	return *this;
}
