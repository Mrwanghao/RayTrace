#include "ViewPlane.h"
#include "Sampler.h"


void ViewPlane::SetSampler(Sampler * _sampler)
{
	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}

	sampler = _sampler;
	samplesCount = sampler->GetSamplesCount();
}

void ViewPlane::SetSamples(int _samplesCount)
{
	samplesCount = _samplesCount;

	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}

	if (samplesCount == 1)
	{
		
	}
	else
	{
		

	}

}

ViewPlane::ViewPlane()
	:
	maxDepth(UINT16_MAX),
	sampler(nullptr)
{
}

ViewPlane::ViewPlane(int _hres, int _wres, float _s)
	:
	maxDepth(UINT16_MAX),
	hres(_hres),
	wres(_wres),
	s(_s),
	sampler(nullptr)
{
}


ViewPlane::~ViewPlane()
{
	if (sampler)
	{
		delete sampler;
		sampler = nullptr;
	}
}
