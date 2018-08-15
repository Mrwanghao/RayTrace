#pragma once
#include "BRDF.h"
#include "Vect3.h"

class ShadeRec;

class PerfectSpecular : public BRDF
{
public:
	PerfectSpecular(void);
	~PerfectSpecular(void);
	virtual PerfectSpecular* Clone(void) const;
	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;

	inline void SetKr(const float k) { kr = k; }
	inline void SetCr(const Vect3& c) { cr = c; }
private:

	float	kr;			
	Vect3 	cr;		

};