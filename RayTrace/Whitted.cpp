#include "Whitted.h"
#include "Ray.h"
#include "World.h"
#include "Color.h"
#include "ShadeRec.h"
#include "Material.h"

Whitted::Whitted()
	:
	Tracer()
{
}

Whitted::Whitted(World * _world)
	:
	Tracer(_world)
{
}

Whitted::~Whitted()
{
}

Vect3 Whitted::trace_ray(const Ray ray, int depth) const
{
	if (depth > world_ptr->vp.maxDepth)
		return Color::Black;
	else {
		ShadeRec sr(world_ptr->hitObjects(ray));

		if (sr.hitAnObject) {
			sr.depth = depth;
			sr.ray = ray;
			return sr.materialPtr->Shade(sr);
		}
		else
			return Color::Black;
	}
}
