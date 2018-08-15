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

PerfectSpecular::~PerfectSpecular(void)
{
}

PerfectSpecular * PerfectSpecular::Clone(void) const
{
	return new PerfectSpecular(*this);
}

Vect3 PerfectSpecular::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	return Color::Black;
}

//���ط����ȥ����ɫ�ͷ���
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

Vect3 PerfectSpecular::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return Color::Black;
}
