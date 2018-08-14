#include "Triangle.h"

Triangle::Triangle()
	:
	GeometricObject(),
	v0(0.0f, 0.0f, 0.0f),
	v1(0.0f, 0.0f, 1.0f),
	v2(1.0f, 0.0f, 0.0f),
	normal(0.0f, 1.0f, 0.0f)
{
}

Triangle::Triangle(const Vect3 & a, const Vect3 & b, const Vect3 & c)
	:
	GeometricObject(),
	v0(a),
	v1(b),
	v2(c)
{
	ComputeNormal();
}

Triangle * Triangle::Clone() const
{
	return new Triangle(*this);
}

Triangle::Triangle(const Triangle & right)
	:
	GeometricObject(right),
	v0(right.v0),
	v1(right.v1),
	v2(right.v2),
	normal(right.normal)
{
}

Triangle::~Triangle()
{
}

Triangle & Triangle::operator=(const Triangle & right)
{
	if (this == &right)
		return (*this);

	GeometricObject::operator=(right);

	v0 = right.v0;
	v1 = right.v1;
	v2 = right.v2;
	normal = right.normal;

	return (*this);
}

void Triangle::ComputeNormal()
{
	normal = (v1 - v0) ^ (v2 - v0);
	normal.Normalize();
}

bool Triangle::Hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	return false;
}

bool Triangle::ShadowHit(const Ray & ray, double & tmin) const
{
	return false;
}
