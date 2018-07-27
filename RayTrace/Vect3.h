#pragma once


class Vect3
{
public:
	union 
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};

public:
	Vect3();
	Vect3(float _x, float _y, float _z);

public:
	Vect3 operator-(const Vect3& right) const;
	float operator*(const Vect3& right) const;
	Vect3 operator*(float scale) const;
	Vect3 operator/(float scale) const;
	Vect3 operator+(const Vect3& right) const;

	friend Vect3 operator*(float scale, const Vect3& right);
};