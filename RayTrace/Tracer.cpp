#include "Tracer.h"



Tracer::Tracer()
	:
	world_ptr(nullptr)
{
}

Tracer::Tracer(World * _world_ptr)
	:
	world_ptr(_world_ptr)
{
}


Tracer::~Tracer()
{
}

Vect3 Tracer::trace_ray(const Ray & _ray) const
{
	return Vect3(0.0f, 0.0f, 0.0f);
}
