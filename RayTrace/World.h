#pragma once
#include "ViewPlane.h"
#include "Sphere.h"

class Tracer;

class World
{
public:
	ViewPlane vp;
	Tracer* tracer_ptr;

	Sphere sphere;

public:
	World();
	~World();

public:
	void Build();
	void RenderScene() const;
	void OpenWindow(int hres, int wres) const;
	void DisplayPixel(int row, int col) const;
};

