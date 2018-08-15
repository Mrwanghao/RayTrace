#pragma once
#include "BRDF.h"
class Lambertian :
	public BRDF
{
public:
	Lambertian();
	Lambertian(const Lambertian& right);
	Lambertian& operator=(const Lambertian& right);
	virtual Lambertian* Clone() const;

	virtual ~Lambertian();

	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;

public:
	inline void SetKA(float _ka) { kd = _ka; }
	inline void SetCD(const Vect3& _cd) { cd = _cd; }
	inline void SetKD(float _kd) { kd = _kd; }

private:
	float kd;
	Vect3 cd;
};

