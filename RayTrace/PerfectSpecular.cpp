#include "PerfectSpecular.h"
#include "Color.h"
#include "ShadeRec.h"
#include <math.h>

PerfectSpecular::PerfectSpecular(void)
	:
	BRDF(),
	kr(1.0f),
	cr(1.0f, 1.0f, 1.0f)
{
}


PerfectSpecular * PerfectSpecular::Clone(void) const
{
	return new PerfectSpecular(*this);
}

PerfectSpecular & PerfectSpecular::operator=(const PerfectSpecular & right)
{
	if (this == &right)
	{
		return *this;
	}

	kr = right.kr;
	cr = right.cr;

	return *this;
}

PerfectSpecular::~PerfectSpecular()
{
}

//返回反射出去的颜色和方向
Vect3 PerfectSpecular::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi) const
{
	float ndotwo = sr.hitNormal.Dot(wo);
	wi = -wo + 2.0 * sr.hitNormal * ndotwo;
	wi.Normalize();
	return kr * cr / fabsf(sr.hitNormal.Dot(wi));
}

Vect3 PerfectSpecular::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi, float & pdf) const
{
	float ndotwo = sr.hitNormal.Dot(wo);
	wi = -wo + 2.0 * sr.hitNormal * ndotwo;
	wi.Normalize();
	pdf = fabsf(sr.hitNormal.Dot(wi));
	return kr * cr;
}