#pragma once
#include "ViewPlane.h"
#include "Tracer.h"

class World
{
public:
	ViewPlane vp;
	Tracer* tracer_ptr;

public:
	World();
	~World();

public:
	void Build();
	void RenderScene() const;
	void OpenWindow(int hres, int wres) const;
	void DisplayPixel(int row, int col) const;
};

