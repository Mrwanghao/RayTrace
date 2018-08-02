#pragma once


class Vect2
{
public:
	union 
	{
		struct
		{
			float x;
			float y;
		};
		float asArray[2];
	};

public:
	Vect2();
	Vect2(float _x, float _y);

public:
	void Normalize();
	Vect2 GetNormalized() const;
	float GetLength() const;

public:
	Vect2 operator/(float scale) const;
	void operator/=(float scale);
};