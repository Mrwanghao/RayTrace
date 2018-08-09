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
	void Normalize();
	Vect3 GetNormalized() const;
	float GetLength() const;
	float Dot(const Vect3& right) const;
	inline void LoadZero() { x = y = z = 0.0f; }

public:
	Vect3 operator-(const Vect3& right) const;
	void operator/=(float scale);
	Vect3 operator*(const Vect3& right) const;
	Vect3 operator*(float scale) const;
	Vect3 operator/(float scale) const;
	Vect3 operator+(const Vect3& right) const;
	void operator+=(const Vect3& right);
	Vect3 operator^(const Vect3& right) const;
	Vect3 operator-() const;
	Vect3 operator+=(float scale);
	
	friend Vect3 operator*(float scale, const Vect3& right);
};