#include "GeometricObject.h"
#include "Material.h"
#include "Matte.h"

GeometricObject::GeometricObject()
	:
	material(nullptr)
{
}

GeometricObject::GeometricObject(const GeometricObject & right)
{
	if (right.material)
		material = right.material->Clone();
	else
		material = nullptr;
}

GeometricObject & GeometricObject::operator=(const GeometricObject & right)
{
	if (this == &right)
		return (*this);


	if (material) {
		delete material;
		material = nullptr;
	}

	if (right.material)
		material = right.material->Clone();


	return (*this);
}

GeometricObject::~GeometricObject()
{
	if (material)
	{
		delete material;
		material = nullptr;
	}
}

float GeometricObject::pdf()
{
	return 1.0f;
}

bool GeometricObject::ShadowHit(const Ray & ray, float & tmin) const
{
	return false;
}

Vect3 GeometricObject::GetNormal() const
{
	return Vect3(0.0f, 0.0f, 0.0f);
}

Vect3 GeometricObject::GetNormal(const Vect3 & point) const
{
	return Vect3(0.0f, 0.0f, 0.0f);
}

Vect3 GeometricObject::Sample()
{
	return Vect3(0.0f, 0.0f, 0.0f);
}

float GeometricObject::pdf(ShadeRec & sr)
{
	return 0.0f;
}
