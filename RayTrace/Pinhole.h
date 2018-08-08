#pragma once


#include "Camera.h"
#include "Vect2.h"
#include "World.h"

class Pinhole : public Camera
{
public:
	Pinhole();
	Pinhole(const Pinhole& right);
	virtual Camera* Clone() const;
	Pinhole& operator=(const Pinhole& right);
	virtual ~Pinhole();

public:
	inline void SetViewDistance(float _distance) { distance = _distance; }
	inline void SetZoom(float _zoom) { zoom = _zoom; }
	Vect3 GetDirection(const Vect2& point) const;
	virtual void RenderScene(const World& _world);

private:
	float distance;
	float zoom;

};
