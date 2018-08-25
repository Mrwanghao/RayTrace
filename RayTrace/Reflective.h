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

	void SetKR(const float k) { reflectiveBRDF->SetKr(k); }
	void SetCR(const Vect3& c) { reflectiveBRDF->SetCr(c); }

	virtual Vect3 Shade(ShadeRec& s);
	virtual Vect3 PathShade(ShadeRec& sr);

private: 
	PerfectSpecular * reflectiveBRDF;

};