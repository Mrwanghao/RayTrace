#pragma once
#include "Vect3.h"

class World;
class Ray;


class Tracer
{
protected:
	World* world_ptr;

public:
	Tracer();
	Tracer(World* _world_ptr);
	virtual ~Tracer();

public:
	virtual Vect3 trace_ray(const Ray& _ray) const;
};

