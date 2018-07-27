#include "ShadeRec.h"


ShadeRec::ShadeRec(World & _world)
	:
	world(_world),
	hitAnObject(false),
	hitLocalPosition(),
	hitNormal(),
	color()
{
}

ShadeRec::ShadeRec(const ShadeRec & right)
	:
	world(right.world),
	hitAnObject(right.hitAnObject),
	hitLocalPosition(right.hitLocalPosition),
	hitNormal(right.hitNormal),
	color(right.color)
{
}

ShadeRec::~ShadeRec()
{
}

ShadeRec & ShadeRec::operator=(const ShadeRec & right)
{
	// TODO: 在此处插入 return 语句
	world = right.world;
	hitAnObject = right.hitAnObject;
	hitLocalPosition = right.hitLocalPosition;
	hitNormal = right.hitNormal;
	color = right.color;
	return *this;
}
