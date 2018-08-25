#include "Sphere.h"
#include <math.h>
#include "Matte.h"
#include "Color.h"

const double Sphere::kEpsilon = 0.01;

Sphere::Sphere()
	:
	GeometricObject(),
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
	double a = _ray.direction.Dot(_ray.direction);
	double b = 2.0 * temp.Dot(_ray.direction);
	double c = temp.Dot(temp) - radius * radius;

	double disc = b * b - 4.0 * a * c;

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
			sr.hitPosition = _ray.origin + _ray.direction * t;
			sr.hitAnObject = true;
			sr.color = Color::Red;
			sr.ray = _ray;

			return true;
		}

		t = (-b + e) / denorn;
		
		if (t > kEpsilon && (_ray.origin - center).GetLength() - radius > kEpsilon)
		{
			tmin = t;
			sr.hitNormal = (temp + t * _ray.direction) / radius;
			sr.hitPosition = _ray.origin + t * _ray.direction;
			sr.hitAnObject = true;
			sr.color = Color::Red;
			sr.ray = _ray;

			return true;
		}

		return false;
	}
}

GeometricObject * Sphere::Clone() const
{
	return new Sphere(*this);
}

bool Sphere::ShadowHit(const Ray & _ray, float & tmin) const
{
	double t;
	Vect3 temp = _ray.origin - center;
	double a = _ray.direction.Dot(_ray.direction);
	double b = 2.0 * temp.Dot(_ray.direction);
	double c = temp.Dot(temp) - radius * radius;

	double disc = b * b - 4.0 * a * c;

	if (disc < 0.0)
	{
		return false;
	}
	else
	{
		double e = sqrtf(disc);
		double denorn = 2.0 * a;
		t = (-b - e) / denorn;

		if (t > kEpsilon)
		{
			tmin = t;
			return true;
		}

		t = (-b + e) / denorn;

		if (t > kEpsilon)
		{
			tmin = t;
			return true;
		}

		return false;
	}
}
