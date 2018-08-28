#include "GlossySpecular.h"
#include "Color.h"
#include "ShadeRec.h"
#include "MultiJittered.h"
#include <math.h>

GlossySpecular::GlossySpecular()
	:
	BRDF(),
	ks(1.0f),
	cs(1.0f, 1.0f, 1.0f),
	exp(1.0f)
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
	//wo为视角
	Vect3 L;
	float ndotwi = sr.hitNormal.Dot(-wi);
	Vect3 r(wi + 2.0f * sr.hitNormal * ndotwi);
	r.Normalize();
	float rdotwo = r.Dot(wo);

	if (rdotwo > 0.0f)
		L = ks * cs * pow(rdotwo, exp);
	
	return L;
}

Vect3 GlossySpecular::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi, float & pdf) const
{
	float ndotwo = sr.hitNormal.Dot(wo);
	Vect3 r = -wo + 2.0 * sr.hitNormal * ndotwo;     

	Vect3 w = r;
	Vect3 u = Vect3(0.00424, 1, 0.00764) ^ w;
	u.Normalize();
	Vect3 v = u ^ w;

	Vect3 sp = sampler->SampleHemisphere();
	wi = sp.x * u + sp.y * v + sp.z * w;			

	if (sr.hitNormal.Dot(wi) < 0.0) 						
		wi = -sp.x * u - sp.y * v + sp.z * w;
	
	//反射光与采样光 r与wi的夹角必定小于90
	float phong_lobe = pow(r.Dot(wi), exp);
	pdf = sr.hitNormal.Dot(wi); //到时候使用的时候仍然会被除cos

	return ks * cs * phong_lobe;
}

void GlossySpecular::SetSampler(Sampler * _sampler, const float exp)
{
	sampler = _sampler;
	sampler->MapSamplesToHemisphere(exp);
}

void GlossySpecular::SetSamples(const int samplesCount, const float exp)
{
	sampler = new MultiJittered(samplesCount);
	sampler->MapSamplesToHemisphere(exp);
}
