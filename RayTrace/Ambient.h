#pragma once
#include "Light.h"
class Ambient : public Light
{
public:
	Ambient();
	Ambient(const Ambient& right);

	virtual Light* Clone() const;
	Ambient& operator=(const Ambient& right);

	virtual ~Ambient();

	inline void SetRadiance(float _radiance) { ls = _radiance; }
	inline void SetColor(const Vect3& _color) { color = _color; }
	virtual Vect3 GetDirection(ShadeRec& sr);
	virtual Vect3 L(ShadeRec& sr);

public:
	void SetRadiance(float _ls) { ls = _ls; }
	void SetColor(const Vect3& _color) { color = _color; }

private:
	float ls;
	Vect3 color;

};