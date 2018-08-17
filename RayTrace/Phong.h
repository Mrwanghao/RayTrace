#pragma once
#include "Material.h"
#include "Lambertian.h"
#include "GlossySpecular.h"
#include "Vect3.h"

class ShadeRec;

class Phong : public Material
{
public:
	Phong();
	Phong(const Phong& right);
	virtual Material* Clone() const;
	Phong& operator=(const Phong& right);
	virtual ~Phong();

	virtual Vect3 Shade(ShadeRec& sr);
public:
	inline void SetKA(float _ka) { ambientBRDF->SetKA(_ka); }
	inline void SetKD(float _kd) { diffuseBRDF->SetKD(_kd); }
	inline void SetCD(const Vect3& _cd)
	{
		ambientBRDF->SetCD(_cd);
		diffuseBRDF->SetCD(_cd);
		specularBRDF->SetCS(_cd);
	}
	inline void SetKS(float _ks) { specularBRDF->SetKS(_ks); }
	inline void SetEXP(float _exp) { specularBRDF->SetEXP(_exp); }

private:
	Lambertian * ambientBRDF;
	Lambertian * diffuseBRDF;
	GlossySpecular* specularBRDF;
};

