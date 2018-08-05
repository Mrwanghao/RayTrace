#include "BRDF.h"

BRDF::BRDF()
	:
	sampler(nullptr)
{
}

BRDF::BRDF(const BRDF & right)
{
	if (right.sampler)
	{
		sampler = right.sampler->Clone();
	}
	else
	{
		sampler = nullptr;
	}
}

BRDF & BRDF::operator=(const BRDF & right)
{
	if (this == &right)
	{
		return *this;
	}

	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}

	if (right.sampler)
	{
		sampler = right.sampler->Clone();
	}

	return  *this;
}

BRDF::~BRDF()
{
	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}
}

void BRDF::SetSampler(Sampler * _sampler)
{
	sampler = _sampler;
	sampler->MapSamplesToHemisphere(1);
}

Vect3 BRDF::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	return Color::Black;
}

Vect3 BRDF::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi) const
{
	return Color::Black;
}

Vect3 BRDF::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi, float & pdf) const
{
	return Color::Black;
}

Vect3 BRDF::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return Color::Black;
}
