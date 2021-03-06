#pragma once
#include "Light.h"
#include "Vect3.h"

class Sampler;
class ShadeRec;
class Ray;

class AmbientOccluder : public Light
{
public:
	AmbientOccluder();
	virtual AmbientOccluder* Clone() const { return new AmbientOccluder(*this); }
	virtual ~AmbientOccluder();

	virtual Vect3 GetDirection(ShadeRec& sr);
	virtual Vect3 L(ShadeRec& sr);

public:
	void SetSampler(Sampler* _sampler);
	virtual bool InShadow(const Ray& ray, const ShadeRec& sr) const;
	virtual inline void SetRadiance(float _ls) { ls = _ls; }
	virtual inline void SetColor(const Vect3& _color) { color = _color; }
	virtual inline void SetDirection(const Vect3& _direction) {  }

private:
	Vect3 u, v, w;
	Sampler* sampler;
	Vect3 color;
	float ls;
	static float minAmount;
};
