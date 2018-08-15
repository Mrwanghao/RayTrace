#include "Tracer.h"
#include "World.h"
#include "Color.h"

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
	if (world_ptr)
	{
		delete world_ptr;
		world_ptr = nullptr;
	}
}


//传入一个射线 然后返回一个颜色
Vect3 Tracer::trace_ray(const Ray & _ray) const
{
	return Color::Black;
}

Vect3 Tracer::trace_ray(const Ray _ray, int _depth) const
{
	return Color::Black;
}

Vect3 Tracer::trace_ray(const Ray _ray, float & _tmin, int _depth) const
{
	return Color::Black;
}
