#include "Reflective.h"
#include "ShadeRec.h"
#include "World.h"
#include "Ray.h"
#include "Tracer.h"

Reflective::Reflective(void)
	:
	Phong(),
	reflectiveBRDF(new PerfectSpecular)
{
}

Reflective::Reflective(const Reflective & rm)
	:
	Phong(rm)
{
	if (rm.reflectiveBRDF)
		reflectiveBRDF = rm.reflectiveBRDF->Clone();
	else
		reflectiveBRDF = NULL;
}

Reflective & Reflective::operator=(const Reflective & rhs)
{
	if (this == &rhs)
		return (*this);

	Phong::operator=(rhs);

	if (reflectiveBRDF) {
		delete reflectiveBRDF;
		reflectiveBRDF = NULL;
	}

	if (rhs.reflectiveBRDF)
		reflectiveBRDF = rhs.reflectiveBRDF->Clone();

	return (*this);
}

Reflective * Reflective::Clone(void) const
{
	return (new Reflective(*this));
}

Reflective::~Reflective(void)
{
	if (reflectiveBRDF) {
		delete reflectiveBRDF;
		reflectiveBRDF = NULL;
	}
}

//光路可逆
Vect3 Reflective::Shade(ShadeRec & sr)
{
	Vect3 L(Phong::Shade(sr)); 

	Vect3 wo = -sr.ray.direction;
	Vect3 wi;
	//获得出射辐射度
	Vect3 fr = reflectiveBRDF->samplef(sr, wo, wi);
	fr.Normalize();
	Ray reflectedRay(sr.hitPosition, wi);

	//获得入射辐射度
	Vect3 color = sr.world->tracer_ptr->trace_ray(reflectedRay, sr.depth + 1);

	//进行光线与本地颜色的混合(因为是镜面反射，所以不衰变)
	Vect3 value = fr * color * (sr.hitNormal.Dot(wi));
	L += value;

	return L;
}

Vect3 Reflective::PathShade(ShadeRec & sr)
{
	return Vect3();
}
