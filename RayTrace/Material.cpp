#include "Material.h"
#include "Color.h"

Material::Material()
{
}

Material::Material(const Material & right)
{
}

Material::~Material()
{
}

Vect3 Material::Shade(ShadeRec & sr)
{
	return Color::Black;
}

Vect3 Material::LE(ShadeRec & sr)
{
	return Color::Black;
}

Vect3 Material::AreaLightShade(ShadeRec & sr)
{
	return Color::Black;
}

Vect3 Material::PathShade(ShadeRec & sr)
{
	return Color::Black;
}

Material & Material::operator=(const Material & right)
{
	if (this == &right)
	{
		return *this;
	}

	return *this;
}
