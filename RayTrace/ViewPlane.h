#pragma once
class ViewPlane
{
public:
	int hres;
	int wres;
	float s;
	float gamma;
	float invGamma;

public:
	ViewPlane();
	ViewPlane(int _hres, int _wres, float _s);
	~ViewPlane();
};

