#include "GlossyReflector.h"

GlossyReflector::GlossyReflector()
	:
	Phong(),
	specularBRDF(new GlossySpecular)
{
}

GlossyReflector::GlossyReflector(const GlossyReflector & right)
	:
	Phong(right)
{
	if (right.specularBRDF)
		specularBRDF = right.specularBRDF->Clone();
	else
		specularBRDF = NULL;
}

Material * GlossyReflector::Clone() const
{
	return new GlossyReflector(*this);
}

GlossyReflector & GlossyReflector::operator=(const GlossyReflector & right)
{
	if (this == &right)
	{
		return *this;
	}

	if (specularBRDF)
	{
		delete specularBRDF;
		specularBRDF = NULL;
	}

	if (right.specularBRDF)
	{
		specularBRDF = right.specularBRDF->Clone();
	}
	else
	{
		specularBRDF = NULL;
	}
	return *this;
}

Vect3 GlossyReflector::Shade(ShadeRec & sr)
{
	return Vect3();
}

GlossyReflector::~GlossyReflector()
{
}
