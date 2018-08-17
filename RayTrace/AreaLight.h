#pragma once
#include "Light.h"
#include "Material.h"
class GeometricObject;
class ShadeRec;


class AreaLight : public Light
{
public:
	AreaLight();
	AreaLight(const AreaLight& right);
	virtual AreaLight* Clone() const;
	AreaLight& operator=(const AreaLight& right);
	virtual Vect3 GetDirection(ShadeRec& sr);
	virtual bool InShadow(const Ray& _ray, const ShadeRec& sr) const;
	virtual Vect3 L(const ShadeRec& sr) const;
	virtual float G(const ShadeRec& sr) const;
	virtual float pdf(ShadeRec& sr) const;

	virtual ~AreaLight();

	void SetObject(GeometricObject* _objPtr) { objPtr = _objPtr; materialPtr = objPtr->GetMaterial(); }
	float pdf(ShadeRec& sr) { return objPtr->pdf(); }

	virtual inline void SetRadiance(float _ls) {}
	virtual inline void SetColor(const Vect3& _color) {}
	virtual inline void SetDirection(const Vect3& _direction) {}

private:
	GeometricObject * objPtr;
	Material* materialPtr;
	Vect3 samplePoint;
	Vect3 lightNormal;
	Vect3 wi;
};