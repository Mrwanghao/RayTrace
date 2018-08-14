#include "Vect3.h"
#include <math.h>

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

void Vect3::Normalize()
{
	float length = GetLength();
	if (length == 0) 
		return;
	*this /= length;
}

Vect3 Vect3::GetNormalized() const
{
	float length = GetLength();
	if (length == 0) return *this;
	return Vect3(x / length, y / length, z / length);
}

float Vect3::GetLength() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vect3::GetLengthSq() const
{
	return x * x + y * y + z * z;
}

float Vect3::Dot(const Vect3& right) const
{
	return x * right.x + y * right.y + z * right.z;
}

Vect3 Vect3::operator-(const Vect3 & right) const
{
	return Vect3(x - right.x, y - right.y, z - right.z);
}

void Vect3::operator/=(float scale)
{
	x /= scale;
	y /= scale;
	z /= scale;
}

Vect3 Vect3::operator*(const Vect3 & right) const
{
	return Vect3(x * right.x, y * right.y, z * right.z);
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

void Vect3::operator+=(const Vect3 & right)
{
	*this = *this + right;
}

Vect3 Vect3::operator^(const Vect3 & right) const
{
	return (Vect3(y * right.z - z * right.y, z * right.x - x * right.z, x * right.y - y * right.x));
}

Vect3 Vect3::operator-() const
{
	return Vect3(-x, -y, -z);
}

void Vect3::operator+=(float scale)
{
	x += scale;
	y += scale;
	z += scale;
}

Vect3 operator*(float scale, const Vect3 & right)
{
	return Vect3(scale * right.x, scale * right.y, scale * right.z);
}
