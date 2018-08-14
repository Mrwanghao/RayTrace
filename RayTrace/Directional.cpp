#include "Directional.h"
#include "World.h"

Directional::Directional()
	:
	Light(),
	ls(1.0f),
	color(0.0f, 0.0f, 0.0f),
	direction(0.0f, 0.0f, 1.0f)
{
}

Directional::Directional(const Directional & right)
	:
	Light(right),
	ls(right.ls),
	color(right.color),
	direction(right.direction)
{
}

Light * Directional::Clone() const
{
	return new Directional(*this);
}

Directional & Directional::operator=(const Directional & right)
{
	if (this == &right)
		return *this;

	Light::operator=(right);

	ls = right.ls;
	color = right.color;
	direction = right.direction;

	return *this;
}

Vect3 Directional::GetDirection(ShadeRec & sr)
{
	direction.Normalize();
	return direction;
}

Vect3 Directional::L(ShadeRec & sr)
{
	return color * ls;
}

Directional::~Directional()
{
}

bool Directional::InShadow(const Ray & ray, const ShadeRec & sr) const
{
	float t;
	int objectsCount = sr.world->GetObjects().size();
	float distance = FLT_MAX;

	for (int j = 0; j < objectsCount; j++)
	{
		if (sr.world->objects[j]->ShadowHit(ray, t) && t < distance)
		{
			return true;
		}
	}

	return false;
}


