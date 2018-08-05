#pragma once
#include "ViewPlane.h"
#include "Sphere.h"
#include "Plane.h"
#include <vector>


class Tracer;
class Light;

class World
{
public:
	ViewPlane vp;
	Tracer* tracer_ptr;
	Light* ambientPtr;

	Sphere sphere;

private:
	std::vector<Light*> lights;
	std::vector<GeometricObject*> objects;

public:
	std::vector<GeometricObject*>& GetObjects() { return objects; }

public:
	World();
	~World();

public:
	void Build();
	void RenderScene() const;
	void OpenWindow(int hres, int wres) const;
	void DisplayPixel(int row, int col) const;
	void AddObject(GeometricObject* _object) { objects.push_back(_object); }
	void AddLight(Light* _light) { lights.push_back(_light); }
};

