#pragma once
#include "Ray.h"
#include "Vect3.h"



class BBox 
{
public:
	double x0, x1, y0, y1, z0, z1;

	BBox();
	BBox(const double& _x0, const double& _x1,
		 const double& _y0, const double& _y1, 
		 const double& _z0, const double& _z1);
	BBox(const Vect3& p0, const Vect3& p1);
	BBox(const BBox& right);
	BBox& operator=(const BBox& right);
	~BBox();

	bool Hit(const Ray& ray) const;
	bool Inside(const Vect3& point) const;


};
