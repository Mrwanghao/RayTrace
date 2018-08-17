#include "Light.h"

Light::Light()
	:
	IsShadow(true)
{
}

Light::Light(const Light & right)
	:
	IsShadow(right.IsShadow)
{
}

Light & Light::operator=(const Light & right)
{
	if (this == &right)
	{
		return *this;
	}

	IsShadow = right.IsShadow;

	return *this;
}


Light::~Light()
{
}

Vect3 Light::L(ShadeRec & sr)
{
	return Color::Black;
}

bool Light::InShadow(const Ray & ray, const ShadeRec & sr) const
{
	return false;
}

float Light::G(const ShadeRec & sr) const
{
	return 1.0f;
}

float Light::pdf(ShadeRec & sr) const
{
	return 1.0f;
}
