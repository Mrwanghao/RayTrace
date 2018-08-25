#include "PerfectTransmitter.h"
#include "Color.h"
#include "ShadeRec.h"
#include <math.h>

PerfectTransmitter::PerfectTransmitter()
	:
	BTDF(),
	iot(1.0f),
	kt(0.0f)
{
}

PerfectTransmitter::PerfectTransmitter(const PerfectTransmitter & right)
	:
	BTDF(right),
	kt(right.kt),
	iot(right.iot)
{
}

PerfectTransmitter & PerfectTransmitter::operator=(const PerfectTransmitter & right)
{
	if (this == &right)
	{
		return *this;
	}

	BTDF::operator=(right);

	kt = right.kt;
	iot = right.iot;

	return *this;
}

PerfectTransmitter::~PerfectTransmitter()
{
}

PerfectTransmitter * PerfectTransmitter::Clone() const
{
	return new PerfectTransmitter(*this);
}

bool PerfectTransmitter::TIR(const ShadeRec & sr) const
{
	Vect3 wo(-sr.ray.direction);
	float cos_thetai = sr.hitNormal.Dot(wo);
	float eta = iot;

	if (cos_thetai < 0.0)
		eta = 1.0 / eta;

	return (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta) < 0.0);
}

Vect3 PerfectTransmitter::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	return Color::Black;
}

Vect3 PerfectTransmitter::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wt) const
{
	Vect3 n(sr.hitNormal);
	float cos_thetai = n.Dot(wo);
	float eta = iot;

	if (cos_thetai < 0.0) {			// transmitted ray is outside     
		cos_thetai = -cos_thetai;
		n = -n;  					// reverse direction of normal
		eta = 1.0 / eta; 			// invert ior 
	}

	float temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
	float cos_theta2 = sqrtf(temp);
	wt = -wo / eta - (cos_theta2 - cos_thetai / eta) * n;

	return (kt / (eta * eta) * Color::White / fabs(sr.hitNormal.Dot(wt)));
}

Vect3 PerfectTransmitter::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return Color::Black;
}
