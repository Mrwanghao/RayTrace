#pragma once
#include "GeometricObject.h"
#include "BBox.h"


class ShadeRec;

class Torus : public GeometricObject
{
public:
	Torus();
	Torus(const double& _a, const double& _b);
	virtual Torus* Clone() const;
	Torus(const Torus& right);
	virtual ~Torus();

	Torus& operator=(const Torus& right);
	Vect3 ComputeNormal(const Vect3& point) const;
	virtual bool Hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

private:
	double a;
	double b;
	BBox bbox;

};

