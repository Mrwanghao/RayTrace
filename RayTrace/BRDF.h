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
	virtual BRDF* Clone() const = 0;

public:
	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const; //用於反射光和鏡面高光反射現象
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi) const; //
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;//環境光的著色

	void SetSampler(Sampler* _sampler);
	
protected:
	Sampler * sampler;
	
};