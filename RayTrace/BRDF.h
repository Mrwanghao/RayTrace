   #pragma once
#include "Sampler.h"
#include "ShadeRec.h"
#include "Vect3.h"
#include "Color.h"

class BRDF
{
public:
	BRDF();
	BRDF(const BRDF& right);
	BRDF& operator=(const BRDF& right);
	virtual ~BRDF();

public:
	void SetSampler(Sampler* _sampler);
	virtual BRDF* Clone() const = 0;
	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;

protected:
	Sampler * sampler;

};