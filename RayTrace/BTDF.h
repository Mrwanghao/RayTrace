#pragma once
#include "Vect3.h"

class ShadeRec;
class Sampler;



class BTDF
{
public:
	BTDF();
	BTDF(const BTDF& right);
	BTDF& operator=(const BTDF& right);
	virtual ~BTDF();
	virtual BTDF* Clone() const;

public:
	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wi) const; 
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;

	

};