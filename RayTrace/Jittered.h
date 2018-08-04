#pragma once
#include "Sampler.h"
#include <math.h>


class Jittered : public Sampler
{
public:
	Jittered();
	Jittered(int _samplesCount);
	Jittered(int _samplesCount, int _setsCount);
	Jittered(const Jittered& right);
	Jittered& operator=(const Jittered& right);
	virtual Jittered* Clone() const;
	~Jittered();

private:
	virtual void GenerateSamples();
};

