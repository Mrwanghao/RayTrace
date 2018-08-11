#include "GlossySpecular.h"
#include "Color.h"

GlossySpecular::GlossySpecular()
	:
	BRDF(),
	ks(0.0f),
	cs(0.0f, 0.0f, 0.0f),
	sampler(nullptr)
{
}
GlossySpecular * GlossySpecular::Clone() const
{
	return new GlossySpecular(*this);
}

GlossySpecular::~GlossySpecular()
{
}

Vect3 GlossySpecular::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	Vect3 L;
	float ndotwi = sr.hitNormal.Dot(-wi);
	Vect3 r(-wi + 2.0f * sr.hitNormal * ndotwi);
	float rdotwo = r.Dot(wo);

	if (rdotwo > 0.0f)
		L = ks * cs * pow(rdotwo, exp);

	return L;
}

Vect3 GlossySpecular::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi, float & pdf) const
{
	return Vect3();
}

Vect3 GlossySpecular::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return Color::Black;
}
