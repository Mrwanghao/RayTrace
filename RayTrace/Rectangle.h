#pragma once

#include "Sampler.h"
#include "GeometricObject.h"

class ShadeRec;

class Rectangle : public GeometricObject 
{
public:
	Rectangle(void);
	Rectangle(const Vect3& _p0, const Vect3& _a, const Vect3& _b);
	Rectangle(const Vect3& _p0, const Vect3& _a, const Vect3& _b, const Vect3& n);
	virtual Rectangle* Clone(void) const;
	Rectangle(const Rectangle& r);
	virtual ~Rectangle(void);
	Rectangle& operator= (const Rectangle& rhs);

	BBox GetBoundingBox(void);
	virtual bool Hit(const Ray& ray, double& t, ShadeRec& s) const;
	virtual void SetSampler(Sampler* sampler);
	virtual Vect3 Sample(void);
	virtual Vect3 GetNormal(const Vect3& p);
	virtual Vect3 GetNormal() const;
	virtual float pdf(ShadeRec& sr);

public:
	virtual inline void SetMaterial(Material* _mat) { material = _mat; }
	virtual inline Material* GetMaterial() { return material; }

private:
	Vect3		p0;   			
	Vect3		a;				
	Vect3		b;				
	double			a_len_squared;	
	double			b_len_squared;	
	Vect3			normal;

	float			area;			
	float			inv_area;		
	Sampler*		sampler_ptr;	

	static const double kEpsilon;




};