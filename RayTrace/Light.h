#pragma once
#include "Vect3.h"
#include "Color.h"	
#include "Ray.h"

class ShadeRec;

class Light
{
public:
	Light();
	Light(const Light& right);
	Light& operator=(const Light& right);
	virtual Light* Clone() const = 0;

	~Light();

public:
	virtual Vect3 GetDirection(ShadeRec& sr) = 0;
	virtual Vect3 L(ShadeRec& sr);
};