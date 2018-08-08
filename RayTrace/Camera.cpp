#include "Camera.h"

void Camera::ComputeUVW()
{
	w = eye - lookat;
	w.Normalize();

	u = up ^ w;
	u.Normalize();

	v = w ^ u;

	if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) {
		u = Vect3(0, 0, 1);
		v = Vect3(1, 0, 0);
		w = Vect3(0, 1, 0);
	}

	if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) {
		u = Vect3(1, 0, 0);
		v = Vect3(0, 0, 1);
		w = Vect3(0, -1, 0);
	}

}
