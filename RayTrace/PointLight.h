#pragma once

#include "Light.h"
#include "ShadeRec.h"
#include "Vect3.h"

class PointLight : public Light
{
public:
	PointLight();
	PointLight(const PointLight& right);

	virtual Light* Clone() const;
	PointLight& operator=(const PointLight& right);
	virtual Vect3 GetDirection(ShadeRec& sr);
	virtual Vect3 L(ShadeRec& sr);
	virtual ~PointLight();

public:
	virtual inline void SetRadiance(float _ls) { ls = _ls; }
	virtual inline void SetColor(const Vect3& _color) { color = _color; }
	virtual inline void SetPosition(const Vect3& _position) { position = _position; }
	virtual inline void SetDirection(const Vect3& _direction) {  }
	virtual bool InShadow(const Ray& ray, const ShadeRec& sr) const;
	virtual inline void SetShadow(bool _isShadow) { IsShadow = _isShadow; }
	virtual inline bool GetShadow() { return IsShadow; }

private:
	float ls;
	Vect3 color;
	Vect3 position;
};