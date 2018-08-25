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
	Sampler* sampler;
	int samplesCount;
	int maxDepth;

public:
	void SetSampler(Sampler* _sampler);
	void SetSamples(int _samplesCount);
	void SetMaxDepth(int depth) { maxDepth = depth; }
public:
	ViewPlane();
	ViewPlane(int _hres, int _wres, float _s);
	~ViewPlane();
};

