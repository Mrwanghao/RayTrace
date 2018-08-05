#pragma once
#include "World.h"
#include "ShadeRec.h"

class Material
{
public:
	Material();
	Material(const Material& right);
	virtual Material* Clone() const = 0;

	virtual ~Material();

	virtual Vect3 Shade(ShadeRec& sr);

protected:
	Material & operator=(const Material& right);
};