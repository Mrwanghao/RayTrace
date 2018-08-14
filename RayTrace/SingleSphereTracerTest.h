#pragma once
#include "Tracer.h"

class Ray;

class SingleSphereTracerTest : public Tracer
{
public:
	SingleSphereTracerTest();
	SingleSphereTracerTest(World* _world_ptr);
	~SingleSphereTracerTest();

public:
	virtual Vect3 trace_ray(const Ray& _ray) const;
};

