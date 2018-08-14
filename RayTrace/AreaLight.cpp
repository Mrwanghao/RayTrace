#include "AreaLight.h"
#include "ShadeRec.h"
#include "World.h"


AreaLight::AreaLight()
	:
	Light(),
	objPtr(nullptr),
	materialPtr(nullptr)
{
}


AreaLight::AreaLight(const AreaLight& right)
	:
	Light(right)
{
	if (right.objPtr)
		objPtr = right.objPtr->Clone();
	else
		objPtr = nullptr;

	if (right.materialPtr)
		materialPtr = right.materialPtr->Clone();
	else
		materialPtr = nullptr;
}

AreaLight * AreaLight::Clone() const
{
	return new AreaLight(*this);
}

float AreaLight::G(const ShadeRec & sr) const
{
	float ndotd = -lightNormal.Dot(wi);
	float d2 = (samplePoint - sr.hitPosition).GetLengthSq();

	return (ndotd / d2);
}

float AreaLight::pdf(ShadeRec & sr) const
{
	return objPtr->pdf(sr);
}

AreaLight::~AreaLight()
{
	if (objPtr) {
		delete objPtr;
		objPtr = NULL;
	}

	if (materialPtr) {
		delete materialPtr;
		materialPtr = NULL;
	}
}


AreaLight& AreaLight::operator= (const AreaLight& rhs) {
	if (this == &rhs)
		return (*this);

	Light::operator=(rhs);

	if (objPtr) {
		delete objPtr;
		objPtr = NULL;
	}

	if (rhs.objPtr)
		objPtr = rhs.objPtr->Clone();

	if (materialPtr) {
		delete materialPtr;
		materialPtr = NULL;
	}

	if (rhs.materialPtr)
		materialPtr = rhs.materialPtr->Clone();

	return (*this);
}

Vect3 AreaLight::GetDirection(ShadeRec & sr)
{
	samplePoint = objPtr->Sample();    // used in the G function
	lightNormal = objPtr->GetNormal(samplePoint);
	wi = samplePoint - sr.hitPosition;  		// used in the G function
	wi.Normalize();

	return wi;
}

bool AreaLight::InShadow(const Ray & _ray, const ShadeRec & sr) const
{
	float t;
	int num_objects = sr.world->objects.size();
	float ts = (samplePoint - _ray.origin).Dot(_ray.direction);

	for (int j = 0; j < num_objects; j++)
		if (sr.world->objects[j]->ShadowHit(_ray, t) && t < ts)
			return (true);

	return (false);
}
