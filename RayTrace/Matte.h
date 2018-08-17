#pragma once
#include "Material.h"
#include "Lambertian.h"
class Vect3;
class ShadeRec;

class Matte : public Material
{
public:
	Matte();
	Matte(const Matte& right);
	virtual Material* Clone() const;
	Matte& operator=(const Matte& right);
	virtual ~Matte();
	
	virtual Vect3 Shade(ShadeRec& sr);
	virtual Vect3 AreaLightShade(ShadeRec& sr);
	
public:
	inline void SetKA(float _ka) { ambientBRDF->SetKA(_ka); }
	inline void SetKD(float _kd) { diffuseBRDF->SetKD(_kd); }
	inline void SetCD(const Vect3& _cd) 
	{ 
		ambientBRDF->SetCD(_cd); 
		diffuseBRDF->SetCD(_cd);
	}

private:
	Lambertian * ambientBRDF;
	Lambertian * diffuseBRDF;

};