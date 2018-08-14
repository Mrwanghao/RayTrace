#pragma once
#include "Ray.h"
#include "BBox.h"

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

protected:
	Material * material;

public:
	virtual inline void SetMaterial(Material* _mat) { material = _mat; }
	virtual inline Material* GetMaterial() { return material; }
	virtual bool ShadowHit(const Ray& ray, float& tmin) const;
	virtual Vect3 GetNormal() const;
	virtual Vect3 GetNormal(const Vect3& point) const;
	virtual Vect3 Sample();
	virtual float pdf(ShadeRec& sr);
};