#include "SingleSphereTracerTest.h"
#include "ShadeRec.h"
#include "Color.h"
#include "World.h"
#include "MathUtil.h"


Vect3 lightPosition(0.0f, 1000.0f, 0.0f);
Vect3 lightPosition1(1000.0f, 1000.0f, 1200.0f);

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
#if 1
	if (world_ptr->sphere.Hit(_ray, t, sr))
	{
#else
	if (world_ptr->plane.Hit(_ray, t, sr))
	{
#endif

#if 1
		Vect3 lightDirection(
			lightPosition.x - sr.hitPosition.x, 
			lightPosition.y - sr.hitPosition.y,
			lightPosition.z - sr.hitPosition.z);
		lightDirection.Normalize();
		
		Vect3 normal = sr.hitNormal;
		normal.Normalize();

		float cosValue = normal.Dot(lightDirection);
		cosValue = Clamp(0.0f, 1.0f, cosValue);

		return Color::Red * cosValue;
#else
		return Color::Red;
#endif
	}
	else
	{
		return Color::Black;
	}
}
