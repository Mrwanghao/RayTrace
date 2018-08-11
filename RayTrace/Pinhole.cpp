#include "Pinhole.h"
#include "ViewPlane.h"
#include "Tracer.h"
#include "Color.h"
#include "EngineDefine.h"
#include <iostream>
#include "ViewPlane.h"
#include "svpng.inc"
#include "MathUtil.h"
#include "Sampler.h"

Pinhole::Pinhole()
	:
	Camera(),
	zoom(1.0f),
	distance(500.0f)
{
}

Pinhole::Pinhole(const Pinhole & right)
	:
	Camera(right),
	zoom(right.zoom),
	distance(right.distance)
{
}

Camera * Pinhole::Clone() const
{
	return new Pinhole(*this);
}

Pinhole & Pinhole::operator=(const Pinhole & right)
{
	if (this == &right)
	{
		return *this;
	}

	Camera::operator=(right);

	zoom = right.zoom;
	distance = right.distance;

	return *this;
}

Pinhole::~Pinhole()
{
}

Vect3 Pinhole::GetDirection(const Vect2 & point) const
{
	Vect3 dir = point.x * u + point.y * v - distance * w;
	dir.Normalize();
	return dir;
}

void Pinhole::RenderScene(const World & _world)
{
	unsigned char* img = (unsigned char*)malloc(SCREEN_HEIGHT * SCREEN_WIDTH * 3 * sizeof(unsigned char));

	Vect3 L;
	ViewPlane vp(_world.vp);
	Ray	ray;
	Vect2 pp;	
	int n = (int)sqrt(vp.samplesCount);
	Vect2 sp;

	vp.s /= zoom;
	ray.origin = eye;

	for (int r = 0; r < vp.hres; r++)
	{
		for (int c = 0; c < vp.wres; c++) {				
			L = Color::Black;
			
			for (int p = 0, count = vp.samplesCount; p < count; p++)
			{
				sp = vp.sampler->SampleUnitSquare();
				pp.x = vp.s * (c - 0.5 * vp.wres + sp.x);
				pp.y = vp.s * (r - 0.5 * vp.hres + sp.y);
				ray.direction = GetDirection(pp);
				L += _world.tracer_ptr->trace_ray(ray);
			}

			L /= vp.samplesCount;
			L = L * exposureTime;

			L = ColorToMaxOne(L);

			img[((SCREEN_HEIGHT - 1 - r) * SCREEN_WIDTH + SCREEN_WIDTH - 1 - c) * 3 + 0] = (unsigned char)(L.x * 255);
			img[((SCREEN_HEIGHT - 1 - r) * SCREEN_WIDTH + SCREEN_WIDTH - 1 - c) * 3 + 1] = (unsigned char)(L.y * 255);
			img[((SCREEN_HEIGHT - 1 - r) * SCREEN_WIDTH + SCREEN_WIDTH - 1 - c) * 3 + 2] = (unsigned char)(L.z * 255);
		}
		std::cout << "µÚ" << r << "ÐÐäÖÈ¾Íê±Ï" << std::endl;
	}

	svpng(fopen("basic4.png", "wb"), SCREEN_WIDTH, SCREEN_HEIGHT, img, 0);
	free(img);
}
