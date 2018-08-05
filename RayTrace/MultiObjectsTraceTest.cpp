#include "MultiObjectsTraceTest.h"
#include "ShadeRec.h"
#include "Color.h"
#include "World.h"
#include "MathUtil.h"

extern Vect3 lightPosition;
extern Vect3 lightPosition1;

MultiObjectsTraceTest::MultiObjectsTraceTest()
	:
	Tracer(nullptr)
{
}

MultiObjectsTraceTest::MultiObjectsTraceTest(World * _world_ptr)
	:
	Tracer(_world_ptr)
{
}

MultiObjectsTraceTest::~MultiObjectsTraceTest()
{
}

Vect3 MultiObjectsTraceTest::trace_ray(const Ray & _ray) const
{
	ShadeRec sr(world_ptr);
	double tMin = DBL_MAX;
	ShadeRec srMin(world_ptr);
	
	double t;
	for (const auto& object : world_ptr->GetObjects())
	{
		if (object->Hit(_ray, t, sr))
		{
			if (t < tMin)
			{
				tMin = t;
				srMin = sr;
			}
		}
	}

	if (srMin.hitAnObject)
	{
		Vect3 lightDirection(
			lightPosition.x - srMin.hitLocalPosition.x,
			lightPosition.y - srMin.hitLocalPosition.y,
			lightPosition.z - srMin.hitLocalPosition.z);
		lightDirection.Normalize();

		Vect3 normal = srMin.hitNormal;
		normal.Normalize();

		float cosValue = normal.Dot(lightDirection);
		cosValue = Clamp(0.0f, 1.0f, cosValue);

		return srMin.color * cosValue;
	}
	else
	{
		return Color::Black;
	}
}
