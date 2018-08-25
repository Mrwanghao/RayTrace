#include "PointLight.h"
#include "World.h"


PointLight::PointLight()
	:
	ls(0.0f),
	color(0.0f, 0.0f, 0.0f)
{
}

PointLight::PointLight(const PointLight & right)
	:
	ls(right.ls),
	color(right.color)
{
}

Light * PointLight::Clone() const
{
	return new PointLight(*this);
}

PointLight & PointLight::operator=(const PointLight & right)
{
	if (this == &right)
	{
		return *this;
	}

	ls = right.ls;
	color = right.color;

	return *this;
}

Vect3 PointLight::GetDirection(ShadeRec & sr)
{
	return Vect3(sr.hitPosition - position).GetNormalized();
}

//��ʱ��ǵü���˥��
Vect3 PointLight::L(ShadeRec & sr)
{
	return ls * color;
}

PointLight::~PointLight()
{
}

bool PointLight::InShadow(const Ray & ray, const ShadeRec & sr) const
{
	float t;
	int objectsCount = sr.world->GetObjects().size();
	float distance = (position - sr.hitPosition).GetLength();

	for (int j = 0; j < objectsCount; j++)
	{
		if (sr.world->objects[j]->ShadowHit(ray, t) && t < distance)
		{
			return true;
		}
	}

	return false;
}
