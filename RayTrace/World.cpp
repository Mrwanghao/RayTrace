#include "World.h"
#include "EngineDefine.h"
#include "SingleSphereTracerTest.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "svpng.inc"

using namespace std;

World::World()
{
}


World::~World()
{
}

void World::Build()
{
	vp = ViewPlane(SCREEN_HEIGHT, SCREEN_WIDTH, 1);
	tracer_ptr = new SingleSphereTracerTest(this);
	sphere = Sphere(Vect3(0.0f, 0.0f, 0.0f), 10);
}

void World::RenderScene() const
{
	unsigned char img[SCREEN_HEIGHT * SCREEN_WIDTH * 3];

	Ray ray;
	Vect3 color;

	int halfw = vp.wres / 2;
	int halfh = vp.hres / 2;

	for (int row = 0; row < vp.hres; row++)
	{
		for (int col = 0; col < vp.wres; col++)
		{
			ray = Ray(Vect3(col - halfw, row - halfh, -10), Vect3(0, 0, 1));

			color = tracer_ptr->trace_ray(ray);
			
			img[(row * SCREEN_WIDTH + col) * 3    ] = (unsigned char)(color.x * 255);
			img[(row * SCREEN_WIDTH + col) * 3 + 1] = (unsigned char)(color.y * 255);
			img[(row * SCREEN_WIDTH + col) * 3 + 2] = (unsigned char)(color.z * 255);
		}
	}

	svpng(fopen("basic.png", "wb"), SCREEN_WIDTH, SCREEN_HEIGHT, img, 0);
}

void World::OpenWindow(int hres, int wres) const
{
}

void World::DisplayPixel(int row, int col) const
{
}
