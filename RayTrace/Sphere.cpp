#include "Sphere.h"
#include <math.h>

const double Sphere::kEpsilon = 0.01;

Sphere::Sphere()
	:
	center(Vect3(0.0f, 0.0f, 0.0f)),
	radius(1.0f)
{
}

Sphere::Sphere(const Vect3& _center, const double& _radius)
	:
	center(_center),
	radius(_radius)
{
}


Sphere::~Sphere()
{
}

bool Sphere::Hit(const Ray & _ray, double & tmin, ShadeRec & sr) const
{
	double t;
	Vect3 temp = _ray.origin - center;
	double a = _ray.direction * _ray.direction;
	double b = 2.0 * temp * _ray.direction;
	double c = temp * temp - radius * radius;

	double disc = b * b - 2.0 * a * c;

	if (disc < 0.0)
	{
		return false;
	}
	else
	{
		double e = sqrtf(disc);
		double denorn = 2.0 * a;
		t = (-b -e) / denorn;

		if (t > kEpsilon)
		{
			tmin = t;
			sr.hitNormal = (temp + t * _ray.direction) / radius;
			sr.hitLocalPosition = _ray.origin + _ray.direction * t;
			sr.hitAnObject = true;

			return true;
		}

		t = (-b + e) / denorn;
		
		if (t > kEpsilon)
		{
			tmin = t;
			sr.hitNormal = (temp + t * _ray.direction) / radius;
			sr.hitLocalPosition = _ray.origin + t * _ray.direction;
			sr.hitAnObject = true;

			return true;
		}

		return false;
	}
}
