#pragma once
#include "GeometrixObject.h"
#include "Vect3.h"


class Sphere : public GeometricObject
{
private:
	Vect3 center;
	double radius;

	static const double kEpsilon;

public:
	Sphere(const Vect3& _center, const double& _radius);
	~Sphere();

public:
	virtual bool Hit(const Ray& _ray, double& tmin, ShadeRec& sr) const;
};

