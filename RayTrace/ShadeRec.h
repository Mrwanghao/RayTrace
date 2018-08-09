#pragma once

#include "Vect3.h"
#include "Ray.h"

class World;
class Material;

class ShadeRec
{
public:
	bool hitAnObject;
	Vect3 hitPosition;
	Vect3 hitNormal;
	Vect3 color;
	World * world;
	Ray ray;
	Material* materialPtr;
	int depth;
	double t;
	float u;
	float v;

public:
	ShadeRec(World * _world);
	ShadeRec(const ShadeRec& right);
	~ShadeRec();

};

