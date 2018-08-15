#include "PathTrace.h"
#include "World.h"
#include "Ray.h"


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
	return Vect3();
}
