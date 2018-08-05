#pragma once
#include "Light.h"

class Directional : public Light
{
public:
	Directional();
	Directional(const Directional& right);

	virtual Light* Clone() const;
	Directional& operator=(const Directional& right);
	virtual Vect3 GetDirection(ShadeRec& sr);
	virtual Vect3 L(ShadeRec& sr);

public:
	inline void SetRadiance(float _ls) { ls = _ls; }
	inline void SetColor(const Vect3& _color) { color = _color; }
	inline void SetDirection(const Vect3& _direction) { direction = _direction; direction.Normalize(); }


private:
	float ls;
	Vect3 color;
	Vect3 direction;
};