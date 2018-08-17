#pragma once
#include "BRDF.h"
#include "Vect3.h"

class ShadeRec;

class PerfectSpecular : public BRDF
{
public:
	PerfectSpecular(void);
	virtual PerfectSpecular* Clone(void) const;
	PerfectSpecular& operator=(const PerfectSpecular& right);
	virtual ~PerfectSpecular();
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi, float& pdf) const;

	inline void SetKr(const float k) { kr = k; }
	inline void SetCr(const Vect3& c) { cr = c; }
private:
	float	kr;			
	Vect3 	cr;		
};