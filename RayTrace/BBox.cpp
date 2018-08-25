#include "BBox.h"
#include "Plane.h"


BBox::BBox()
	:
	x0(-1),
	x1(1),
	y0(-1),
	y1(1),
	z0(-1),
	z1(1)
{
}

BBox::BBox(const double & _x0, const double & _x1, const double & _y0, const double & _y1, const double & _z0, const double & _z1)
	:
	x0(x0),
	x1(x1),
	y0(y0),
	y1(y1),
	z0(z0),
	z1(z1)
{
}

BBox::BBox(const Vect3 & p0, const Vect3 & p1)
	:
	x0(p0.x),
	x1(p1.x),
	y0(p0.y),
	y1(p1.y),
	z0(p0.z),
	z1(p1.z)
{
}

BBox::BBox(const BBox & right)
	:
	x0(right.x0),
	x1(right.x1),
	y0(right.y0),
	y1(right.y1),
	z0(right.z0),
	z1(right.z1)
{
}

BBox & BBox::operator=(const BBox & right)
{
	if (this == &right)
	{
		return *this;
	}

	x0 = right.x0;
	x1 = right.x1;
	y0 = right.y0;
	y1 = right.y1;
	z0 = right.z0;
	z1 = right.z1;

	return *this;
}

BBox::~BBox()
{
}

//����һ���������ж��Ƿ��ཻ
bool BBox::Hit(const Ray & ray) const
{
	double ox = ray.origin.x; double oy = ray.origin.y; double oz = ray.origin.z;
	double dx = ray.direction.x; double dy = ray.direction.y; double dz = ray.direction.z;

	double tx_min, ty_min, tz_min;
	double tx_max, ty_max, tz_max;

	double a = dx == 0.0f ? 1.0f / 0.000001f : 1.0 / dx;
	if (a >= 0) {
		tx_min = (x0 - ox) * a;
		tx_max = (x1 - ox) * a;
	}
	else {
		tx_min = (x1 - ox) * a;
		tx_max = (x0 - ox) * a;
	}

	double b = dy == 0.0f ? 1.0f / 0.000001f : 1.0f / dy;
	if (b >= 0) {
		ty_min = (y0 - oy) * b;
		ty_max = (y1 - oy) * b;
	}
	else {
		ty_min = (y1 - oy) * b;
		ty_max = (y0 - oy) * b;
	}

	double c = dx == 0.0f ? 1.0f / 0.000001f : 1.0 / dz;
	if (c >= 0) {
		tz_min = (z0 - oz) * c;
		tz_max = (z1 - oz) * c;
	}
	else {
		tz_min = (z1 - oz) * c;
		tz_max = (z0 - oz) * c;
	}

	double t0, t1;

	// find largest entering t value

	if (tx_min > ty_min)
		t0 = tx_min;
	else
		t0 = ty_min;

	if (tz_min > t0)
		t0 = tz_min;

	// find smallest exiting t value

	if (tx_max < ty_max)
		t1 = tx_max;
	else
		t1 = ty_max;

	if (tz_max < t1)
		t1 = tz_max;

	return (t0 < t1 && t1 > Plane::kEpsilon);
}

bool BBox::Inside(const Vect3 & point) const
{
	return ((point.x > x0 && point.x < x1) && (point.y > y0 && point.y < y1) && (point.z > z0 && point.z < z1));
}
