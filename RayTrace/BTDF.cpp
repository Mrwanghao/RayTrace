#include "BTDF.h"
#include "Sampler.h"
#include "ShadeRec.h"
#include "Color.h"


BTDF::BTDF()
{
}

BTDF::BTDF(const BTDF & right)
{
}

BTDF & BTDF::operator=(const BTDF & right)
{
	if (this == &right)
	{
		return *this;
	}

	return  *this;
}

BTDF::~BTDF()
{
}

BTDF * BTDF::Clone() const
{
	return new BTDF(*this);
}

Vect3 BTDF::f(const ShadeRec & sr, const Vect3 & wo, const Vect3 & wi) const
{
	return Color::Black;
}

Vect3 BTDF::samplef(const ShadeRec & sr, const Vect3 & wo, Vect3 & wi) const
{
	return Color::Black;
}

Vect3 BTDF::rho(const ShadeRec & sr, const Vect3 & wo) const
{
	return Color::Black;
}
