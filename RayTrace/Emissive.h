#pragma once



#include "Material.h"


class Emissive : public Material
{

public:
	Emissive();
	Emissive(const Emissive& right);
	virtual Emissive* Clone() const;

	virtual ~Emissive();

	virtual float G(const ShadeRec& sr) const;
	virtual float pdf(const ShadeRec& sr) const;
	virtual Vect3 LE(ShadeRec& sr);

	virtual Vect3 Shade(ShadeRec& sr);
	virtual Vect3 AreaLightShade(ShadeRec& sr);

public:
	inline void SetLS(float _ls) { ls = _ls; }
	inline void SetCE(const Vect3& _ce) { ce = _ce; }

private:
	float ls;
	Vect3 ce;

};
