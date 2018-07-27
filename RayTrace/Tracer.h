#pragma once
#include "World.h"
#include "Ray.h"

class Tracer
{
protected:
	World * world_ptr;

public:
	Tracer();
	Tracer(World* _world_ptr);
	~Tracer();

public:
	virtual Vect3 trace_ray(const Ray& _ray) const;
};

