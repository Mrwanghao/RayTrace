#include "AmbientOccluder.h"
#include "Sampler.h"
#include "Sampler.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "World.h"

float AmbientOccluder::minAmount = 0.0f;

AmbientOccluder::AmbientOccluder()
	:
	sampler(nullptr)
{
}

void AmbientOccluder::SetSampler(Sampler * _sampler)
{
	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}

	sampler = _sampler;
	sampler->MapSamplesToHemisphere(1);
}

Vect3 AmbientOccluder::GetDirection(ShadeRec & sr)
{
	Vect3 sp = sampler->SampleHemisphere();
	Vect3 dir = sp.x * u + sp.y * v + sp.z * w;
	dir.Normalize();
	return dir;
}

bool AmbientOccluder::InShadow(const Ray & ray, const ShadeRec & sr) const
{
	float t;
	int objectsCount = sr.world->objects.size();
	for (int j = 0; j < objectsCount; j++)
	{
		if (sr.world->objects[j]->ShadowHit(ray, t))
		{
			return true;
		}
	}

	return false;
}

Vect3 AmbientOccluder::L(ShadeRec & sr)
{
	w = sr.hitNormal;
	v = w ^ Vect3(0.0072f, 1.0f, 0.0034f);
	v.Normalize();
	u = v ^ w;

	Ray shadowRay;
	shadowRay.origin = sr.hitPosition;
	shadowRay.direction = GetDirection(sr);
	if (InShadow(shadowRay, sr))
	{
		return minAmount * ls * color;
	}
	else
	{
		return ls * color;
	}

}
