#pragma once
#include "Sampler.h"
#include <math.h>


class Jittered : public Sampler
{
public:
	Jittered();
	~Jittered();

private:
	virtual void GenerateSamples();
};

