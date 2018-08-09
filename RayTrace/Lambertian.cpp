#include "Lambertian.h"
#include "EngineDefine.h"


Lambertian::Lambertian()
	:
	BRDF(),
	kd(0.0f),
	cd(0.0f, 0.0f, 0.0f)
{
}

Lambertian::Lambertian(const Lambertian & right)
	:
	BRDF(right),
	kd(right.kd),
	cd(right.cd)
{
}

Lambertian & Lambertian::operator=(const Lambertian & right)
{
	if (this == &right)
	{
		return *this;
	}

	BRDF::operator=(right);

	kd = right.kd;
	cd = right.cd;

	return *this;
}


Lambertian * Lambertian::Clone() const
{
	return new Lambertian(*this);
}

Lambertian::~Lambertian()
{
}

Vect3 Lambertian::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	return kd * cd / PI;
}

Vect3 Lambertian::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi, float & pdf) const
{
	Vect3 w = sr.hitNormal;
	Vect3 v = Vect3(0.0034f, 1, 0.0071f) ^ w;
	v.Normalize();
	Vect3 u = v ^ w;

	Vect3 sp = sampler->SampleHemisphere();
	wi = sp.x * u + sp.y * v + sp.z * w;
	wi.Normalize();

	pdf = sr.hitNormal.Dot(wi)/ PI;

	return kd * cd / PI;
}

Vect3 Lambertian::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return kd * cd;
}
