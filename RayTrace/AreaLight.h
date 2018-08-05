#pragma once
#include "Light.h"

class GeometricObject;
class Material;



class AreaLight
{
public:
	AreaLight();
	AreaLight(const AreaLight& right);
	virtual Light* Clone() const;
	AreaLight& operator=(const AreaLight& right);
	Vect3 GetDirection(ShadeRec& sr);
	virtual bool InShadow(const Ray& _ray, const ShadeRec& sr) const;
	virtual float G(const ShadeRec& sr) const;
	virtual float pdf(const ShadeRec& sr) const;

	virtual ~AreaLight();

	void SetObject(GeometricObject* _objPtr) { objPtr = _objPtr; materialPtr = objPtr->GetMaterial(); }
private:
	GeometricObject * objPtr;
	Material* materialPtr;
	Vect3 samplePoint;
	Vect3 lightNormal;
	Vect3 wi;
};