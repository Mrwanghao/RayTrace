#include "Torus.h"
#include "Plane.h"
#include <cfloat>
#include "ShadeRec.h"

Torus::Torus()
	:
	GeometricObject(),
	a(2.0f),
	b(0.5f),
	bbox(-a-b, a+b, -b, b, -a-b, a+b)
{
}

Torus::Torus(const double & _a, const double & _b)
	:
	GeometricObject(),
	a(_a),
	b(_b),
	bbox(-a - b, a + b, -b, b, -a - b, a + b)
{
}

Torus * Torus::Clone() const
{
	return new Torus(*this);
}

Torus::Torus(const Torus & right)
	:
	GeometricObject(),
	a(right.a),
	b(right.b),
	bbox(right.bbox)
{
}

Torus::~Torus()
{
}

Torus & Torus::operator=(const Torus & right)
{
	if (this == &right)
		return (*this);

	GeometricObject::operator=(right);

	a = right.a;
	b = right.b;
	bbox = right.bbox;

	return (*this);
}

Vect3 Torus::ComputeNormal(const Vect3 & p) const
{
	Vect3 normal;
	double param_squared = a * a + b * b;

	double x = p.x;
	double y = p.y;
	double z = p.z;
	double sum_squared = x * x + y * y + z * z;

	normal.x = 4.0 * x * (sum_squared - param_squared);
	normal.y = 4.0 * y * (sum_squared - param_squared + 2.0 * a * a);
	normal.z = 4.0 * z * (sum_squared - param_squared);
	normal.Normalize();

	return (normal);
}

bool Torus::Hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	//if (!bbox.Hit(ray))
	//	return (false);
	//
	//double x1 = ray.origin.x; double y1 = ray.origin.y; double z1 = ray.origin.z;
	//double d1 = ray.direction.x; double d2 = ray.direction.y; double d3 = ray.direction.z;
	//
	//double coeffs[5];	// coefficient array for the quartic equation
	//double roots[4];	// solution array for the quartic equation
	//
	//					// define the coefficients of the quartic equation
	//
	//double sum_d_sqrd = d1 * d1 + d2 * d2 + d3 * d3;
	//double e = x1 * x1 + y1 * y1 + z1 * z1 - a * a - b * b;
	//double f = x1 * d1 + y1 * d2 + z1 * d3;
	//double four_a_sqrd = 4.0 * a * a;
	//
	//coeffs[0] = e * e - four_a_sqrd * (b * b - y1 * y1); 	// constant term
	//coeffs[1] = 4.0 * f * e + 2.0 * four_a_sqrd * y1 * d2;
	//coeffs[2] = 2.0 * sum_d_sqrd * e + 4.0 * f * f + four_a_sqrd * d2 * d2;
	//coeffs[3] = 4.0 * sum_d_sqrd * f;
	//coeffs[4] = sum_d_sqrd * sum_d_sqrd;  					// coefficient of t^4
	//
	//														// find roots of the quartic equation
	//
	//int num_real_roots = SolveQuartic(coeffs, roots);
	//
	//bool	intersected = false;
	//double 	t = DBL_MAX;
	//
	//if (num_real_roots == 0)  // ray misses the torus
	//	return(false);
	//
	//// find the smallest root greater than kEpsilon, if any
	//// the roots array is not sorted
	//
	//for (int j = 0; j < num_real_roots; j++)
	//	if (roots[j] > Plane::kEpsilon) {
	//		intersected = true;
	//		if (roots[j] < t)
	//			t = roots[j];
	//	}
	//
	//if (!intersected)
	//	return (false);
	//
	//tmin = t;
	//sr.hitPosition = ray.origin + t * ray.direction;
	//sr.hitNormal = ComputeNormal(sr.hitPosition);
	//
	return (false);
}
