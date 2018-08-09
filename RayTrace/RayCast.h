#pragma once



#include "Tracer.h"
#include "Vect3.h"


class Ray;
class World;


class RayCast : public Tracer
{
public:
	RayCast();
	RayCast(World* _world);
	virtual ~RayCast();
	virtual Vect3 trace_ray(const Ray& ray) const;
	
};