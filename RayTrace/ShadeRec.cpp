#include "ShadeRec.h"
#include "World.h"
#include "Color.h"
#include "Material.h"

ShadeRec::ShadeRec(World* _world)
	:
	hitAnObject(false),
	hitPosition(),
	hitNormal(),
	color(Color::Black),
	world(_world),
	ray(),
	materialPtr(nullptr),
	depth(0),
	t(0.0f),
	u(0.0f),
	v(0.0f)
{
}

ShadeRec::ShadeRec(const ShadeRec & right)
	:
	hitAnObject(right.hitAnObject),
	hitPosition(right.hitPosition),
	hitNormal(right.hitNormal),
	color(right.color),
	world(right.world),
	ray(right.ray),
	materialPtr(right.materialPtr),
	depth(right.depth),
	t(right.t),
	u(right.u),
	v(right.v)
{
}

ShadeRec::~ShadeRec()
{
	//if (materialPtr)
	//{
	//	delete materialPtr;
	//	materialPtr = nullptr;
	//}
}


