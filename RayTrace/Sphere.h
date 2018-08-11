#pragma once
#include "GeometricObject.h"
#include "Vect3.h"
#include "ShadeRec.h"


class Sphere : public GeometricObject
{
private:
	Vect3 center;
	double radius;

	static const double kEpsilon;

public:
	Sphere();
	Sphere(const Vect3& _center, const double& _radius);
	~Sphere();

public:
	virtual bool Hit(const Ray& _ray, double& tmin, ShadeRec& sr) const;
	virtual GeometricObject* Clone() const;
	virtual bool ShadowHit(const Ray& ray, float& tmin) const;
};

