#include "Tracer.h"
#include "World.h"
#include "Color.h"

Tracer::Tracer()
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


//����һ������ Ȼ�󷵻�һ����ɫ
Vect3 Tracer::trace_ray(const Ray & _ray) const
{
	return Color::Black;
}
