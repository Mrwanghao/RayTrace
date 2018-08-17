#pragma once
#include "Phong.h"
#include "GlossySpecular.h"


class GlossyReflector : public Phong
{
public:
	GlossyReflector();
	GlossyReflector(const GlossyReflector& right);
	virtual Material* Clone() const;
	GlossyReflector& operator=(const GlossyReflector& right);
	virtual ~GlossyReflector();

	virtual Vect3 Shade(ShadeRec& sr);
public:
	inline void SetSamples(const int _samplesCount, const float _exp) { specularBRDF->SetSamples(_samplesCount, _exp); }
	inline void SetKR(float _kr) { specularBRDF->SetKS(_kr); }
	inline void SetExponent(float _exp) { specularBRDF->SetEXP(_exp); }
private:
	GlossySpecular* specularBRDF;

};