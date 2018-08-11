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
#include "PointLight.h"

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
	ambientPtr->SetRadiance(1.0f);
	ambientPtr->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	vp = ViewPlane(SCREEN_HEIGHT, SCREEN_WIDTH, 1);
	vp.SetSampler(new MultiJittered(16));
	tracer_ptr = new RayCast(this);

	mainCamera = new Pinhole();
	mainCamera->SetEye(Vect3(0.0f, 0.0f, -200.0f));
	mainCamera->SetExposureTime(1.0f);
	mainCamera->SetRoll(0.0f);
	mainCamera->SetUp(Vect3(0.0f, 1.0f, 0.0f));
	mainCamera->SetLookAt(Vect3(0.0f, 0.0f, 0.0f));
	mainCamera->ComputeUVW();

	sphere = Sphere(Vect3(0.0f, 0.0f, 1500.0f), 100);

	Phong* material = new Phong();
	material->SetKS(0.5f);
	material->SetEXP(5.0f);
	material->SetKA(0.2f);
	material->SetKD(0.3f);
	material->SetCD(Vect3(1.0f, 1.0f, 0.0f));

	//Light* lightPtr = new Directional();
	//lightPtr->SetRadiance(1.0f);
	//lightPtr->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	//lightPtr->SetDirection(Vect3(0.0f, -1.0f, 1.0f));
	//lights.push_back(lightPtr);

	PointLight* pointLightPtr = new PointLight();
	pointLightPtr->SetRadiance(1.0f);
	pointLightPtr->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	pointLightPtr->SetPosition(Vect3(0.0f, 400.0f, 0.0f));
	lights.push_back(pointLightPtr);

	Sphere* spherePtr = new Sphere(Vect3(0.0f, 0.0f, 500.0f), 100);
	spherePtr->SetMaterial(material);
	objects.push_back(spherePtr);

	Plane* plane = new Plane(Vect3(0.0f, 1.0f, 0.0f), Vect3(0.0f, -500.0f, 0.0f));
	plane->SetMaterial(material);
	objects.push_back(plane);
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
