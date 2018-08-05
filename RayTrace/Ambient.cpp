#include "Ambient.h"

Ambient::Ambient()
	:
	Light(),
	ls(1.0f),
	color(1.0f, 1.0f, 1.0f)
{
}

Ambient::Ambient(const Ambient & right)
	:
	Light(right),
	ls(right.ls),
	color(right.color)
{
}

Light * Ambient::Clone() const
{
	return new Ambient(*this);
}

Ambient & Ambient::operator=(const Ambient & right)
{
	if (this == &right)
	{
		return *this;
	}

	Light::operator=(right);

	ls = right.ls;
	color = right.color;

	return *this;
}

Ambient::~Ambient()
{
}

Vect3 Ambient::GetDirection(ShadeRec & sr)
{
	return Vect3(0.0f, 0.0f, 0.0f);
}

Vect3 Ambient::L(ShadeRec & sr)
{
	return ls * color;
}
