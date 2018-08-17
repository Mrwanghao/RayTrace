#include "Reflective.h"
#include "ShadeRec.h"
#include "World.h"
#include "Ray.h"
#include "Tracer.h"

Reflective::Reflective(void)
	:
	Phong(),
	reflective_brdf(new PerfectSpecular)
{
}

Reflective::Reflective(const Reflective & rm)
	:
	Phong(rm)
{
	if (rm.reflective_brdf)
		reflective_brdf = rm.reflective_brdf->Clone();
	else
		reflective_brdf = NULL;
}

Reflective & Reflective::operator=(const Reflective & rhs)
{
	if (this == &rhs)
		return (*this);

	Phong::operator=(rhs);

	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}

	if (rhs.reflective_brdf)
		reflective_brdf = rhs.reflective_brdf->Clone();

	return (*this);
}

Reflective * Reflective::Clone(void) const
{
	return (new Reflective(*this));
}

Reflective::~Reflective(void)
{
	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}
}

//光路可逆
Vect3 Reflective::Shade(ShadeRec & sr)
{
	Vect3 L(Phong::Shade(sr)); 

	Vect3 wo = -sr.ray.direction;
	Vect3 wi;
	//获得出射辐射度
	Vect3 fr = reflective_brdf->samplef(sr, wo, wi);
	fr.Normalize();
	Ray reflected_ray(sr.hitPosition, wi);

	//获得入射辐射度
	Vect3 color = sr.world->tracer_ptr->trace_ray(reflected_ray, sr.depth + 1);

	//进行光线与本地颜色的混合(因为是镜面反射，所以不衰变)
	Vect3 value = fr * color * (sr.hitNormal.Dot(wi));
	L += value;

	return L;
}
