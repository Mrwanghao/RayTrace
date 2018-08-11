#pragma once
#include "Tracer.h"

class Ray;

class MultiObjectsTraceTest : public Tracer
{
public:
	MultiObjectsTraceTest();
	MultiObjectsTraceTest(World* _world_ptr);
	~MultiObjectsTraceTest();

public:
	Vect3 trace_ray(const Ray& _ray) const override;
};