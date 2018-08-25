#include "World.h"
#include "EngineDefine.h"
#include "SingleSphereTracerTest.h"
#include "MultiObjectsTraceTest.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "MultiJittered.h"
#include "RayCast.h"
#include "Pinhole.h"
#include "Light.h"
#include "Matte.h"
#include "Ambient.h"
#include "Directional.h"
#include "Phong.h"
#include "AmbientOccluder.h"
#include "PointLight.h"
#include "Reflective.h"
#include "Whitted.h"
#include "AreaLight.h"
#include "Rectangle.h"
#include "Emissive.h"
#include "PathTrace.h"
#include "Transparent.h"

using namespace std;

const double World::kEpsilon = 0.01;

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
	ambientPtr = new Ambient();
	ambientPtr->SetRadiance(0.4f);
	ambientPtr->SetColor(Color::White);
	//AmbientOccluder* ambient = new AmbientOccluder();
	//ambient->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	//ambient->SetRadiance(1.0f);
	//ambient->SetSampler(new MultiJittered(256));
	//ambient->SetShadow(true);
	//ambientPtr = ambient;
	vp = ViewPlane(SCREEN_HEIGHT, SCREEN_WIDTH, 1);
	vp.SetSampler(new MultiJittered(16));
	vp.SetMaxDepth(5);
	tracer_ptr = new Whitted(this);

	mainCamera = new Pinhole();
	mainCamera->SetEye(Vect3(0.0f, 0.0f, -500.0f));
	mainCamera->SetExposureTime(1.0f);
	mainCamera->SetRoll(0.0f);
	mainCamera->SetUp(Vect3(0.0f, 1.0f, 0.0f));
	mainCamera->SetLookAt(Vect3(0.0f, 0.0f, 0.0f));
	mainCamera->ComputeUVW();

	sphere = Sphere(Vect3(0.0f, 0.0f, 1500.0f), 100);

	Transparent* transparent = new Transparent();
	transparent->SetKS(0.5f);
	transparent->SetEXP(2000.0f);
	transparent->SetIOT(1.5f);
	transparent->SetKR(0.1f);
	transparent->SetKT(0.9f);
	transparent->SetCD(Vect3(0.0f, 0.0f, 0.0f));

	Sphere* sphere = new Sphere(Vect3(0.0f, -400.0f, 600.0f), 100);
	sphere->SetMaterial(transparent);
	objects.push_back(sphere);

	Matte* material2 = new Matte();
	material2->SetCD(Vect3(0.3f, 0.3f, 1.0f));
	material2->SetKA(0.25f);
	material2->SetKD(0.75f);
	Sphere* sphere2 = new Sphere(Vect3(100.0f, -400.0f, 800.0f), 100);
	sphere2->SetMaterial(material2);
	objects.push_back(sphere2);

	Matte* material = new Matte();
	material->SetCD(Vect3(0.3f, 1.0f, 0.3f));
	material->SetKA(0.25f);
	material->SetKD(0.75f);
	Plane* plane = new Plane(Vect3(0.0f, 1.0f, 0.0f), Vect3(0.0f, -500.0f, 0.0f));
	plane->SetMaterial(material);
	objects.push_back(plane);

	PointLight* pointlight = new PointLight();
	pointlight->SetColor(Color::White);
	pointlight->SetPosition(Vect3(0.0f, 0.0f, 0.0f));
	pointlight->SetRadiance(1.0f);
	lights.push_back(pointlight);

	//Emissive* emisssive = new Emissive();
	//emisssive->SetLS(4000.0f);
	//emisssive->SetCE(Color::White);
	//
	//Rectangle* rectanglePtr = new Rectangle();
	//rectanglePtr->SetMaterial(emisssive);
	//rectanglePtr->SetSampler(new MultiJittered(16));
	//objects.push_back(rectanglePtr);
	//
	//AreaLight* arealight = new AreaLight();
	//arealight->SetColor(Color::White);
	//arealight->SetObject(rectanglePtr);
	//lights.push_back(arealight);
	//
	//Matte* matte = new Matte();
	//matte->SetCD(Vect3(1.0f, 0.3f, 0.3f));
	//matte->SetKA(0.25f);
	//matte->SetKD(0.75f);
	//
	//Sphere* s1 = new Sphere(Vect3(0.0f, -400.0f, 600.0f), 100);
	//s1->SetMaterial(matte);
	//objects.push_back(s1);
	//
	//Matte* material = new Matte();
	//material->SetCD(Vect3(0.3f, 1.0f, 0.3f));
	//material->SetKA(0.25f);
	//material->SetKD(0.75f);
	//Plane* plane = new Plane(Vect3(0.0f, 1.0f, 0.0f), Vect3(0.0f, -500.0f, 0.0f));
	//plane->SetMaterial(material);
	//objects.push_back(plane);

}

void World::RenderScene() const
{
	mainCamera->RenderScene(*this);
}

ShadeRec World::hitObjects(const Ray & ray)
{
	ShadeRec sr(this);
	double t;
	Vect3 normal;
	Vect3 hitPosition;
	float tmin = DBL_MAX;
	int objectsCount = objects.size();

	for (int j = 0; j < objectsCount; j++)
	{
		if (objects[j]->Hit(ray, t, sr) && t < tmin)
		{
			sr.hitAnObject = true;
			tmin = t;
			sr.materialPtr = objects[j]->GetMaterial();
			sr.hitPosition = ray.origin + ray.direction * t;
			normal = sr.hitNormal;
			hitPosition = sr.hitPosition;
		}
	}

	if (sr.hitAnObject)
	{
		sr.t = tmin;
		sr.hitNormal = normal;
		sr.hitPosition = hitPosition;
	}
	
	return sr;
}
