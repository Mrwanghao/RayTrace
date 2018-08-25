#pragma once

#include "BRDF.h"

class Sampler;
class ShadeRec;

class GlossySpecular : public BRDF
{
public:
	GlossySpecular();

	virtual GlossySpecular* Clone() const;
	virtual ~GlossySpecular();

	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;

public:
	inline void SetKS(float _ks) { ks = _ks; }
	inline void SetEXP(float _exp) { exp = _exp; }
	inline void SetCS(const Vect3& _cs) { cs = _cs; }
	inline void SetSampler(Sampler* _sampler) { sampler = _sampler; }
	void SetSampler(Sampler* _sampler, const float exp);
	void SetSamples(const int samplesCount, const float exp);
private:
	float ks;
	float exp;
	Vect3 cs;
};
