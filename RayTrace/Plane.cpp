#include "Plane.h"

static const double kEpsilon = 0.01;

Plane::Plane()
{
}

Plane::Plane(const Vect3 & normal, const Vect3 & point)
{
}


Plane::~Plane()
{
}

bool Plane::Hit(const Ray & _ray, double & tmin, ShadeRec & sr) const
{
	double t = (point - _ray.origin) * normal / (_ray.direction * normal);

	if (t > kEpsilon)
	{
		tmin = t;
		sr.hitNormal = normal;
		sr.hitAnObject = true;
		sr.hitLocalPosition = _ray.origin + _ray.direction * t;


	}
	else
	{
		return false;
	}
}
