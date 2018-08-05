#include "GeometricObject.h"
#include "Material.h"

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
