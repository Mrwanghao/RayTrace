#include "Emissive.h"
#include "Color.h"


Emissive::Emissive()
	:
	Material(),
	ls(1.0f),
	ce(1.0f, 1.0f, 1.0f)
{
}

Emissive::Emissive(const Emissive & right)
	:
	Material(right),
	ls(right.ls),
	ce(right.ce)
{
}

Emissive * Emissive::Clone() const
{
	return new Emissive(*this);
}

Emissive::~Emissive()
{
}

float Emissive::G(const ShadeRec & sr) const
{
	return 0.0f;
}

float Emissive::pdf(const ShadeRec & sr) const
{
	return 0.0f;
}

Vect3 Emissive::LE(ShadeRec & sr)
{
	return ce * ls;
}

Vect3 Emissive::Shade(ShadeRec & sr)
{
	return ls * ce;
}

Vect3 Emissive::AreaLightShade(ShadeRec & sr)
{
	if (-sr.hitNormal.Dot(sr.ray.direction) > 0.0f)
	{
		return ls * ce;
	}
	else
	{
		return Color::Black;
	}
}
