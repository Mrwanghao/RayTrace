#include "Rectangle.h"
#include <math.h>
#include "ShadeRec.h"
#include "MultiJittered.h"

const double Rectangle::kEpsilon = 0.01f;

Rectangle::Rectangle(void)
	: 
	GeometricObject(),
	p0(0, 0, 500),
	a(0, 200, 500),
	b(200, 0, 500),
	a_len_squared(40000.0),
	b_len_squared(40000.0),
	normal(0, 0, -1),
	area(4000.0),
	inv_area(0.00025),
	sampler_ptr(new MultiJittered(16))
{
}

Rectangle::Rectangle(const Vect3 & _p0, const Vect3 & _a, const Vect3 & _b)
	:
	GeometricObject(),
	p0(_p0),
	a(_a),
	b(_b),
	a_len_squared(a.GetLengthSq()),
	b_len_squared(b.GetLengthSq()),
	area(a.GetLength() * b.GetLength()),
	inv_area(1.0 / area),
	sampler_ptr(NULL)
{
}

Rectangle::Rectangle(const Vect3 & _p0, const Vect3 & _a, const Vect3 & _b, const Vect3 & n)
	:
	GeometricObject(),
	p0(_p0),
	a(_a),
	b(_b),
	a_len_squared(a.GetLengthSq()),
	b_len_squared(b.GetLengthSq()),
	area(a.GetLength() * b.GetLength()),
	inv_area(1.0 / area),
	normal(n),
	sampler_ptr(NULL)
{
	normal.Normalize();
}

Rectangle * Rectangle::Clone(void) const
{
	return (new Rectangle(*this));
}

Rectangle::Rectangle(const Rectangle & r)
	:
	GeometricObject(r),
	p0(r.p0),
	a(r.a),
	b(r.b),
	a_len_squared(r.a_len_squared),
	b_len_squared(r.b_len_squared),
	normal(r.normal),
	area(r.area),
	inv_area(r.inv_area)
{
	if (r.sampler_ptr)
		sampler_ptr = r.sampler_ptr->Clone();
	else  sampler_ptr = NULL;
}

Rectangle::~Rectangle(void)
{
	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}
}

Rectangle & Rectangle::operator=(const Rectangle & rhs)
{
	if (this == &rhs)
		return (*this);

	GeometricObject::operator=(rhs);

	p0 = rhs.p0;
	a = rhs.a;
	b = rhs.b;
	a_len_squared = rhs.a_len_squared;
	b_len_squared = rhs.b_len_squared;
	area = rhs.area;
	inv_area = rhs.inv_area;
	normal = rhs.normal;

	if (sampler_ptr) {
		delete sampler_ptr;
		sampler_ptr = NULL;
	}

	if (rhs.sampler_ptr)
		sampler_ptr = rhs.sampler_ptr->Clone();

	return (*this);
}

BBox Rectangle::GetBoundingBox(void)
{
	double delta = 0.0001;

	return(BBox(fminf(p0.x, p0.x + a.x + b.x) - delta, fmaxf(p0.x, p0.x + a.x + b.x) + delta,
		fminf(p0.y, p0.y + a.y + b.y) - delta, fmaxf(p0.y, p0.y + a.y + b.y) + delta,
		fminf(p0.z, p0.z + a.z + b.z) - delta, fmaxf(p0.z, p0.z + a.z + b.z) + delta));
}

bool Rectangle::Hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	double t = (p0 - ray.origin).Dot(normal) / (ray.direction.Dot(normal));

	if (t <= kEpsilon)
		return (false);

	Vect3 p = ray.origin + t * ray.direction;
	Vect3 d = p - p0;

	double ddota = d.Dot(a);

	if (ddota < 0.0 || ddota > a_len_squared)
		return (false);

	double ddotb = d.Dot(b);

	if (ddotb < 0.0 || ddotb > b_len_squared)
		return (false);

	tmin = t;
	sr.hitNormal = normal;
	sr.hitPosition = p;
	sr.ray = ray;

	return (true);
}

void Rectangle::SetSampler(Sampler * sampler)
{
	sampler_ptr = sampler;
}

Vect3 Rectangle::Sample(void)
{
	Vect2 sample_point = sampler_ptr->SampleUnitSquare();
	return (p0 + sample_point.x * a + sample_point.y * b);
}

Vect3 Rectangle::GetNormal(const Vect3 & p)
{
	return normal;
}

Vect3 Rectangle::GetNormal() const
{
	return normal;
}

float Rectangle::pdf(ShadeRec & sr)
{
	return inv_area;
}
