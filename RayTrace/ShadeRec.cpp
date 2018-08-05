#include "ShadeRec.h"
#include "Color.h"

ShadeRec::ShadeRec(World* _world)
	:
	world(_world),
	hitAnObject(false),
	hitLocalPosition(),
	hitNormal(),
	color(Color::Black),
	t(0.0f),
	u(0.0f),
	v(0.0f),
	depth(0),
	materialPtr(nullptr),
	ray()
{
}

ShadeRec::ShadeRec(const ShadeRec & right)
	:
	world(right.world),
	hitAnObject(right.hitAnObject),
	hitLocalPosition(right.hitLocalPosition),
	hitNormal(right.hitNormal),
	color(right.color),
	t(right.t),
	u(right.u),
	v(right.v),
	depth(right.depth),
	materialPtr(right.materialPtr),
	ray(right.ray)
{
}

ShadeRec::~ShadeRec()
{
	if (materialPtr)
	{
		delete materialPtr;
		materialPtr = nullptr;
	}
}

ShadeRec & ShadeRec::operator=(const ShadeRec & right)
{
	world = right.world;
	hitAnObject = right.hitAnObject;
	hitLocalPosition = right.hitLocalPosition;
	hitNormal = right.hitNormal;
	color = right.color;
	return *this;
}
