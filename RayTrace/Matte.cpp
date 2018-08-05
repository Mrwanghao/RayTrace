#include "Matte.h"

Matte::Matte()
	:
	Material(),
	ambientBRDF(new Lambertian),
	diffuseBRDF(new Lambertian)
{
}

Matte::Matte(const Matte & right)
	:
	Material(right)
{
	if (right.ambientBRDF)
	{
		ambientBRDF = right.ambientBRDF->Clone();
	}
	else
	{
		ambientBRDF = nullptr;
	}

	if (right.diffuseBRDF)
	{
		diffuseBRDF = right.diffuseBRDF->Clone();
	}
	else
	{
		diffuseBRDF = nullptr;
	}
}

Material * Matte::Clone() const
{
	return new Matte(*this);
}

Matte & Matte::operator=(const Matte & right)
{
	if (this == &right)
	{
		return *this;
	}

	Material::operator=(right);

	if (ambientBRDF)
	{
		delete ambientBRDF;
		ambientBRDF = nullptr;
	}

	if (right.ambientBRDF)
	{
		ambientBRDF = right.ambientBRDF->Clone();
	}

	if (diffuseBRDF)
	{
		delete diffuseBRDF;
		diffuseBRDF = nullptr;
	}

	if (right.diffuseBRDF)
	{
		diffuseBRDF = right.diffuseBRDF->Clone();
	}

	return *this;
}

Vect3 Matte::Shade(ShadeRec & sr)
{
	//Vect3 wo = -sr.ray.direction;
	//Vect3 L = ambientBRDF->rho(sr, wo);
	//
	//
	//return L;
	return Vect3();
}

Matte::~Matte()
{
	if (ambientBRDF)
	{
		delete ambientBRDF;
		ambientBRDF = nullptr;
	}

	if (diffuseBRDF)
	{
		delete diffuseBRDF;
		diffuseBRDF = nullptr;
	}
}
