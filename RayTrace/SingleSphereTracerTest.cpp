#include "SingleSphereTracerTest.h"
#include "ShadeRec.h"
#include "Color.h"
#include "World.h"

SingleSphereTracerTest::SingleSphereTracerTest()
	:
	Tracer(nullptr)
{
}

SingleSphereTracerTest::SingleSphereTracerTest(World * _world_ptr)
	:
	Tracer(_world_ptr)
{
}


SingleSphereTracerTest::~SingleSphereTracerTest()
{
}

Vect3 SingleSphereTracerTest::trace_ray(const Ray & _ray) const
{
	ShadeRec sr(world_ptr);
	double t;

	if (world_ptr->sphere.Hit(_ray, t, sr))
	{
		return Color::Red;
	}
	else
	{
		return Color::Black;
	}
}
