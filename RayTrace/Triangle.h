#pragma once
#include "GeometricObject.h"
#include "Vect3.h"

class Triangle : public GeometricObject
{
public:
	Triangle();
	Triangle(const Vect3& a, const Vect3& b, const Vect3& c);
	virtual Triangle* Clone() const;
	Triangle(const Triangle& right);
	~Triangle();
	Triangle& operator=(const Triangle& right);
	void ComputeNormal();
	virtual bool Hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
	virtual bool ShadowHit(const Ray& ray, double& tmin) const;

private:
	Vect3 v0, v1, v2;
	Vect3 normal;

};


