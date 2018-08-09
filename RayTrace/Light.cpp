#include "Light.h"

Light::Light()
{
}

Light::Light(const Light & right)
{
}

Light & Light::operator=(const Light & right)
{
	if (this == &right)
	{
		return *this;
	}

	return *this;
}


Light::~Light()
{
}

Vect3 Light::L(ShadeRec & sr)
{
	return Color::Black;
}
