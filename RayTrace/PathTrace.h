#pragma once
#include "Tracer.h"

class World;
class Ray;

class PathTrace : public Tracer
{
public:
	PathTrace();
	PathTrace(World* _world);
	virtual ~PathTrace();
	virtual Vect3 trace_ray(const Ray& ray, int depth) const;

};