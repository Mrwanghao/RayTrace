#pragma once
#include "Ray.h"
#include "ShadeRec.h"

class GeometricObject
{
public:
	virtual bool Hit(const Ray& _ray, double& tmin, ShadeRec& sr) const = 0;

};