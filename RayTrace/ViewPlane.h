#pragma once

class Sampler;

class ViewPlane
{
public:
	int hres;
	int wres;
	float s;
	float gamma;
	float invGamma;
	Sampler* sampler = nullptr;
	int samplesCount;
	int maxDepth;

public:
	void SetSampler(Sampler* _sampler);
	void SetSamples(int _samplesCount);

public:
	ViewPlane();
	ViewPlane(int _hres, int _wres, float _s);
	~ViewPlane();
};

