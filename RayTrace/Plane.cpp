#include "Plane.h"
#include "Color.h"
#include "ShadeRec.h"
#include "Matte.h"

const double Plane::kEpsilon = 0.01;

Plane::Plane()
	:
	GeometricObject()
{
}

Plane::Plane(const Vect3 & normal, const Vect3 & point)
	:
	normal(normal),
	point(point)
{
	this->normal.Normalize();
}


Plane::~Plane()
{
}

bool Plane::Hit(const Ray & _ray, double & tmin, ShadeRec & sr) const
{
	double t = (point - _ray.origin).Dot(normal) / (_ray.direction.Dot(normal));

	if (t > kEpsilon)
	{
		tmin = t;
		sr.hitNormal = normal;
		sr.hitAnObject = true;
		sr.hitPosition = _ray.origin + _ray.direction * t;
		sr.color = Color::Green;
		sr.ray = _ray;

		return true;
	}
	else
	{
		return false;
	}
}

GeometricObject * Plane::Clone() const
{
	return new Plane(*this);
}
