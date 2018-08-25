#include "Transparent.h"
#include "World.h"
#include <math.h>
#include "Tracer.h"

Transparent::Transparent()
	:
	Phong(),
	reflectiveBRDF(new PerfectSpecular),
	specularBTDF(new PerfectTransmitter)
{
}

Transparent::Transparent(const Transparent & right)
	:
	Phong(right)
{
	if (reflectiveBRDF)
	{
		delete reflectiveBRDF;
		reflectiveBRDF = nullptr;
	}

	if (right.reflectiveBRDF)
	{
		reflectiveBRDF = right.reflectiveBRDF->Clone();
	}

	if (specularBTDF)
	{
		delete specularBTDF;
		specularBTDF = nullptr;
	}

	if (right.specularBTDF)
	{
		specularBTDF = right.specularBTDF->Clone();
	}
}

Material * Transparent::Clone() const
{
	return new Transparent(*this);
}

Transparent & Transparent::operator=(const Transparent & right)
{
	if (this == &right)
	{
		return *this;
	}

	Phong::operator=(*this);

	if (reflectiveBRDF)
	{
		delete reflectiveBRDF;
		reflectiveBRDF = nullptr;
	}

	if (right.reflectiveBRDF)
	{
		reflectiveBRDF = right.reflectiveBRDF->Clone();
	}

	if (specularBTDF)
	{
		delete specularBTDF;
		specularBTDF = nullptr;
	}

	if (right.specularBTDF)
	{
		specularBTDF = right.specularBTDF->Clone();
	}

	return *this;
}

Transparent::~Transparent()
{
	if (reflectiveBRDF)
	{
		delete reflectiveBRDF;
		reflectiveBRDF = nullptr;
	}

	if (specularBTDF)
	{
		delete specularBTDF;
		specularBTDF = nullptr;
	}
}

Vect3 Transparent::Shade(ShadeRec & sr)
{
	Vect3 L(Phong::Shade(sr));

	Vect3 wo = -sr.ray.direction;
	Vect3 wi;

	//·´Éä
	Vect3 fr = reflectiveBRDF->samplef(sr, wo, wi);
	Ray reflectedRay(sr.hitPosition, wi);

	if (specularBTDF->TIR(sr))
	{
		//L += Color::Black;
		L += sr.world->tracer_ptr->trace_ray(reflectedRay, sr.depth + 1);
	}
	else
	{
		//L += Color::White;
		Vect3 wt;
		Vect3 ft = specularBTDF->samplef(sr, wo, wt);
		Ray transmittedRay(sr.hitPosition, wt);
		Vect3 color1 = sr.world->tracer_ptr->trace_ray(reflectedRay, sr.depth + 1);
		Vect3 color2 = sr.world->tracer_ptr->trace_ray(transmittedRay, sr.depth + 1);
		L += fr * sr.world->tracer_ptr->trace_ray(reflectedRay, sr.depth + 1) * fabsf(sr.hitNormal.Dot(wi));
		L += ft * sr.world->tracer_ptr->trace_ray(transmittedRay, sr.depth + 1) * fabsf(sr.hitNormal.Dot(wt));

	}

	return L;
}
