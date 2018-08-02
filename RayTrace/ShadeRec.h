#pragma once

#include "Vect3.h"

class World;
class ShadeRec;

class ShadeRec
{
public:
	bool hitAnObject;
	Vect3 hitLocalPosition;
	Vect3 hitNormal;
	Vect3 color;
	World * world;

public:
	ShadeRec(World * _world);
	ShadeRec(const ShadeRec& right);
	~ShadeRec();

public:
	ShadeRec & operator=(const ShadeRec& right);
};

