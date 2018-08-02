#include "Vect2.h"
#include <math.h>

Vect2::Vect2()
	:
	x(0.0f),
	y(0.0f)
{
}

Vect2::Vect2(float _x, float _y)
	:
	x(_x),
	y(_y)
{
}

void Vect2::Normalize()
{
	float length = GetLength();
	if (length == 0) return;
	*this /= length;
}

float Vect2::GetLength() const
{
	return sqrt(x * x + y * y);
}

Vect2 Vect2::operator/(float scale) const
{
	return Vect2(x / scale, y / scale);
}

void Vect2::operator/=(float scale)
{
	x /= scale;
	y /= scale;
}

Vect2 Vect2::GetNormalized() const
{
	float length = GetLength();
	if (length == 0) return *this;
	return Vect2(x / length, y / length);
}
