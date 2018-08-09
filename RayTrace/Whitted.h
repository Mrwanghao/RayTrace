#pragma once
#include "Tracer.h"
#include "Vect3.h"


class Ray;
class World;

class Whitted : public Tracer
{
public:
	Whitted();
	Whitted(World* _world);
	virtual ~Whitted();
	virtual Vect3 trace_ray(const Ray& ray, const int depth) const;

};