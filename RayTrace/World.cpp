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
	//AmbientOccluder* ambient = new AmbientOccluder();
	//ambient->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	//ambient->SetRadiance(1.0f);
	//ambient->SetSampler(new MultiJittered(256));
	//ambient->SetShadow(true);
	//ambientPtr = ambient;
	vp = ViewPlane(SCREEN_HEIGHT, SCREEN_WIDTH, 1);
	vp.SetSampler(new MultiJittered(16));
	vp.SetMaxDepth(10);
	tracer_ptr = new Whitted(this);

	mainCamera = new Pinhole();
	mainCamera->SetEye(Vect3(0.0f, 0.0f, -500.0f));
	mainCamera->SetExposureTime(1.0f);
	mainCamera->SetRoll(0.0f);
	mainCamera->SetUp(Vect3(0.0f, 1.0f, 0.0f));
	mainCamera->SetLookAt(Vect3(0.0f, 0.0f, 0.0f));
	mainCamera->ComputeUVW();

	sphere = Sphere(Vect3(0.0f, 0.0f, 1500.0f), 100);


	PointLight* pointLightPtr = new PointLight();
	pointLightPtr->SetRadiance(1.0f);
	pointLightPtr->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	pointLightPtr->SetPosition(Vect3(0.0f, -200.0f, 400.0f));
	lights.push_back(pointLightPtr);

	//Directional* directionalLightPtr = new Directional();
	//directionalLightPtr->SetColor(Vect3(1.0f, 1.0f, 1.0f));
	//directionalLightPtr->SetRadiance(2.0f);
	//directionalLightPtr->SetDirection(Vect3(0.0f, -1.0f, 1.0f));
	//directionalLightPtr->SetShadow(true);
	//lights.push_back(directionalLightPtr);

	Reflective* spherematerial = new Reflective();
	spherematerial->SetKA(0.25f);
	spherematerial->SetKD(0.75f);
	spherematerial->SetCD(Vect3(1.0f, 1.0f, 1.0f));
	spherematerial->SetKS(1.0f);
	spherematerial->SetEXP(100.0f);
	spherematerial->SetKR(10.0f);
	spherematerial->SetCR(Vect3(1.0f, 1.0f, 1.0f));

	Phong* material = new Phong();
	material->SetKS(0.3f);
	material->SetEXP(5.0f);
	material->SetKA(0.25f);
	material->SetKD(0.75f);
	material->SetCD(Vect3(0.3f, 0.3f, 1.0f));

	Sphere* spherePtr = new Sphere(Vect3(200.0f, -400.0f, 600.0f), 100);
	spherePtr->SetMaterial(spherematerial);
	objects.push_back(spherePtr);

	Reflective* spherematerial2 = new Reflective();
	spherematerial2->SetKA(0.25f);
	spherematerial2->SetKD(0.75f);
	spherematerial2->SetCD(Vect3(0.3f, 1.0f, 0.3f));
	spherematerial2->SetKS(1.0f);
	spherematerial2->SetEXP(100.0f);
	spherematerial2->SetKR(3.0f);
	spherematerial2->SetCR(Vect3(0.3f, 1.0f, 0.3f));
	Sphere* spherePtr2 = new Sphere(Vect3(0.0f, -400.0f, 600.0f), 100);
	spherePtr2->SetMaterial(spherematerial2);
	objects.push_back(spherePtr2);

	//Sphere* spherePtr2 = new Sphere(Vect3(200.0f, -400.0f, 600.0f), 100);
	//spherePtr2->SetMaterial(material);
	//objects.push_back(spherePtr2);
	
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
