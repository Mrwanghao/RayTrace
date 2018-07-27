#include "Vect3.h"

Vect3::Vect3()
	:
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

Vect3::Vect3(float _x, float _y, float _z)
	:
	x(_x),
	y(_y),
	z(_z)
{
}

Vect3 Vect3::operator-(const Vect3 & right) const
{
	return Vect3(x - right.x, y - right.y, z - right.z);
}

float Vect3::operator*(const Vect3 & right) const
{
	return x * right.x + y * right.y + z * right.z;
}

Vect3 Vect3::operator*(float scale) const
{
	return Vect3(x * scale, y * scale, z * scale);
}

Vect3 Vect3::operator/(float scale) const
{
	return Vect3(x / scale, y / scale, z / scale);
}

Vect3 Vect3::operator+(const Vect3 & right) const
{
	return Vect3(x + right.x, y + right.y, z + right.z);
}

Vect3 operator*(float scale, const Vect3 & right)
{
	return Vect3(scale * right.x, scale * right.y, scale * right.z);
}
