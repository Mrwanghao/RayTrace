#include "World.h"
#include "EngineDefine.h"
#include "SingleSphereTracerTest.h"
#include "MultiObjectsTraceTest.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "PureRandom.h"
#include "Regular.h"
#include "NRooks.h"
#include "MultiJittered.h"
#include "Jittered.h"
#include "Hammersley.h"
#include "Pinhole.h"

using namespace std;

World::World()
	:
	tracer_ptr(nullptr)
{
}


World::~World()
{
	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			delete objects[i];
		}
	}

	if (ambientPtr)
	{
		delete ambientPtr;
		ambientPtr = nullptr;
	}

	if (mainCamera)
	{
		delete mainCamera;
		mainCamera;
	}

	if (tracer_ptr)
	{
		delete tracer_ptr;
		tracer_ptr = nullptr;
	}



}

void World::Build()
{
	vp = ViewPlane(SCREEN_HEIGHT, SCREEN_WIDTH, 1);
	vp.SetSampler(new MultiJittered(16));
	//tracer_ptr = new SingleSphereTracerTest(this);
	tracer_ptr = new MultiObjectsTraceTest(this);

	mainCamera = new Pinhole();
	mainCamera->SetEye(Vect3(0.0f, 0.0f, -200.0f));
	mainCamera->SetExposureTime(1.0f);
	mainCamera->SetRoll(0.0f);
	mainCamera->SetUp(Vect3(0.0f, 1.0f, 0.0f));
	mainCamera->SetLookAt(Vect3(0.0f, 0.0f, 0.0f));
	mainCamera->ComputeUVW();


	sphere = Sphere(Vect3(0.0f, 0.0f, 1500.0f), 100);


	objects.push_back(new Sphere(Vect3(600.0f, 100.0f, 1500.0f), 100));
	objects.push_back(new Sphere(Vect3(0.0f, 300.0f, 800.0f), 100));
	objects.push_back(new Sphere(Vect3(0.0f, -300.0f, 400.0f), 100));
	objects.push_back(new Plane(Vect3(0.0f, 15.0f, -1.0f), Vect3(0.0f, 0.0f, 10000.0f)));

}

void World::RenderScene() const
{
	mainCamera->RenderScene(*this);


//	unsigned char* img = (unsigned char*)malloc(SCREEN_HEIGHT * SCREEN_WIDTH * 3 * sizeof(unsigned char));
//
//	Ray ray;
//	Vect3 color;
//	Vect2 pp;
//	Vect2 sp;
//	Vect3 pixelColor;
//
//	ray.direction = Vect3(0, 0, 1);
//	int halfw = (vp.wres - 1) / 2;
//	int halfh = (vp.hres - 1) / 2;
//
//	for (int row = 0; row < vp.hres; row++)
//	{
//		for (int col = 0; col < vp.wres; col++)
//		{
//#if 0
//			ray = Ray(Vect3(col - halfw, row - halfh, -10), Vect3(0, 0, 1));
//			//ray = Ray(Vect3(0, 0, -800), Vect3(col - halfw + 0.5f, row - halfh + 0.5f, 800));
//			color = tracer_ptr->trace_ray(ray);
//#else
//			for (int p = 0; p < vp.samplesCount; p++)
//			{
//				sp = vp.sampler->SampleUnitSquare();
//				pp.x = vp.s * (col - 0.5f * vp.wres + sp.x);
//				pp.y = vp.s * (row - 0.5f * vp.hres + sp.y);
//				ray.origin = Vect3(pp.x, pp.y, -10);
//				pixelColor += tracer_ptr->trace_ray(ray);
//			}
//
//			color = pixelColor / vp.samplesCount;
//			pixelColor.LoadZero();
//#endif
//			
//			img[((SCREEN_HEIGHT - 1 - row) * SCREEN_WIDTH + col) * 3] = (unsigned char)(color.x * 255);
//			img[((SCREEN_HEIGHT - 1 - row) * SCREEN_WIDTH + col) * 3 + 1] = (unsigned char)(color.y * 255);
//			img[((SCREEN_HEIGHT - 1 - row) * SCREEN_WIDTH + col) * 3 + 2] = (unsigned char)(color.z * 255);
//		}
//		std::cout << "��" << row << "����Ⱦ���" << std::endl;
//	}
//
//	svpng(fopen("basic.png", "wb"), SCREEN_WIDTH, SCREEN_HEIGHT, img, 0);
//	free(img);
}

void World::OpenWindow(int hres, int wres) const
{
}

void World::DisplayPixel(int row, int col) const
{
}
