#pragma once

#include "Vect3.h"

class Ray
{
public:
	Vect3 origin;
	Vect3 direction;

public:
	Ray();
	Ray(const Vect3& _origin, const Vect3& _direction);
	Ray(const Ray& right);
	~Ray();


public:
	Ray & operator=(const Ray& right);
};

