#include "PathTrace.h"
#include "World.h"
#include "Ray.h"
#include "Color.h"
#include "ShadeRec.h"
#include "Material.h"

PathTrace::PathTrace()
	:
	Tracer()
{
}

PathTrace::PathTrace(World * _world)
	:
	Tracer(_world)
{
}

PathTrace::~PathTrace()
{
}

Vect3 PathTrace::trace_ray(const Ray & ray, int depth) const
{
	if (depth > world_ptr->vp.maxDepth)
		return Color::Black;
	else
	{
		ShadeRec sr(world_ptr->hitObjects(ray));
		if (sr.hitAnObject)
		{
			sr.ray = ray;
			sr.depth = depth;
			return sr.materialPtr->PathShade(sr);
		}
		else
		{
			return Color::Black;
		}

	}
}
