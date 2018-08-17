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

	virtual ~Light();

protected:
	bool IsShadow;

public:
	
	virtual inline void SetShadow(bool _isShadow) { IsShadow = _isShadow; }
	virtual inline bool GetShadow() { return IsShadow; }
	virtual Vect3 GetDirection(ShadeRec& sr) = 0;
	virtual Vect3 L(ShadeRec& sr);
	virtual bool InShadow(const Ray& ray, const ShadeRec& sr) const;
	virtual float G(const ShadeRec& sr) const;
	virtual float pdf(const ShadeRec& sr) const;

	virtual inline void SetRadiance(float _ls) = 0;
	virtual inline void SetColor(const Vect3& _color) = 0;
	virtual inline void SetDirection(const Vect3& _direction) = 0;
};