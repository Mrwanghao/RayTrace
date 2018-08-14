#pragma once
#include "Phong.h"
#include "PerfectSpecular.h"
#include "Vect3.h"

class ShadeRec;

class Reflective : public Phong
{
public:
	Reflective(void);
	Reflective(const Reflective& rm);
	Reflective& operator= (const Reflective& rhs);
	virtual Reflective* Clone(void) const;
	virtual ~Reflective(void);

	void SetKR(const float k) { reflective_brdf->SetKr(k); }
	void SetCR(const Vect3& c) { reflective_brdf->SetCr(c); }

	virtual Vect3 Shade(ShadeRec& s);

private: 
	PerfectSpecular * reflective_brdf;

};