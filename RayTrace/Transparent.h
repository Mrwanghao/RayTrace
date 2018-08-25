#pragma once

#include "Phong.h"
#include "PerfectSpecular.h"
#include "PerfectTransmitter.h"


class Transparent : public Phong
{
public:
	Transparent();
	Transparent(const Transparent& right);
	virtual Material* Clone() const;
	Transparent& operator=(const Transparent& right);
	virtual ~Transparent();

	virtual Vect3 Shade(ShadeRec& sr);

public:
	inline void SetKT(float kt) { specularBTDF->SetKT(kt); }
	inline void SetIOT(float iot) { specularBTDF->SetIOT(iot); }
	inline void SetKR(float kr) { reflectiveBRDF->SetKr(kr); }
	inline void SetCR(const Vect3& cr) { reflectiveBRDF->SetCr(cr); }
private:
	PerfectSpecular * reflectiveBRDF;
	PerfectTransmitter *specularBTDF;
};