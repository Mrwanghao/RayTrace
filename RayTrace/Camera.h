#pragma once
#include "Vect3.h"

class World;
class Camera
{
protected:
	float exposureTime;
	float roll;
	Vect3 u, v, w;
	Vect3 up;
	Vect3 lookat;
	Vect3 eye;

public:
	void ComputeUVW();
	virtual void RenderScene(const World& _world) = 0;

	inline void SetExposureTime(float _time) { exposureTime = _time; }
	inline void SetUp(const Vect3& _up) { up = _up; }
	inline void SetLookAt(const Vect3& _lookat) { lookat = _lookat; }
	inline void SetEye(const Vect3& _eye) { eye = _eye; }
	inline void SetRoll(float _roll) { roll = _roll; }

};