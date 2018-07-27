#pragma once
#include "GeometrixObject.h"
#include "Vect3.h"

class Plane : public GeometricObject
{
private:
	Vect3 normal;
	Vect3 point;

	static const double kEpsilon;

public:
	Plane();
	Plane(const Vect3& normal, const Vect3& point);
	~Plane();

public:
	virtual bool Hit(const Ray& _ray, double& tmin, ShadeRec& sr) const;
};

