#pragma once
#include "BTDF.h"

class ShadeRec;
class PerfectTransmitter : public BTDF
{
public:
	PerfectTransmitter();
	PerfectTransmitter(const PerfectTransmitter& right);
	PerfectTransmitter& operator=(const PerfectTransmitter& right);
	virtual ~PerfectTransmitter();
	virtual PerfectTransmitter* Clone() const;

	inline void SetKT(const float k) { kt = k; }
	inline void SetIOT(const float eta) { iot = eta; }
	bool TIR(const ShadeRec& sr) const;

public:
	virtual Vect3 f(const ShadeRec& sr, const Vect3& wo, const Vect3& wi) const;
	virtual Vect3 samplef(const ShadeRec& sr, const Vect3& wo, Vect3& wt) const;
	virtual Vect3 rho(const ShadeRec& sr, const Vect3& wo) const;

private:
	float kt;
	float iot;
};