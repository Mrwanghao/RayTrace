#include "RayCast.h"
#include "Ray.h"
#include "World.h"
#include "ShadeRec.h"
#include "Color.h"
#include "Material.h"

RayCast::RayCast()
	:
	Tracer()
{
}

RayCast::RayCast(World * _world)
	:
	Tracer(_world)
{
}

RayCast::~RayCast()
{
}

Vect3 RayCast::trace_ray(const Ray & ray) const
{
	ShadeRec sr(world_ptr->hitObjects(ray));

	if (sr.hitAnObject)
	{
		sr.ray = ray;
#if 1
		return sr.materialPtr->Shade(sr);
#else
		return sr.materialPtr->AreaLightShade(sr);
#endif
	}
	else
	{
		return Color::White;
	}
}
