#pragma once
#include "Ray.h"
//#include "ShadeRec.h"

class ShadeRec;
class Material;

class GeometricObject
{
public:
	virtual bool Hit(const Ray& _ray, double& tmin, ShadeRec& sr) const = 0;
	virtual GeometricObject* Clone() const = 0;


public:
	GeometricObject();
	GeometricObject(const GeometricObject& right);
	GeometricObject& operator=(const GeometricObject& right);
	virtual ~GeometricObject();

private:
	Material * material;

public:
	virtual inline void SetMaterial(Material* _mat) { material = _mat; }
	inline Material* GetMaterial() { return material; }
};