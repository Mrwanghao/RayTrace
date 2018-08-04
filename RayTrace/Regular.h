#pragma once
#include "Sampler.h"
class Regular : public Sampler
{
public:
	Regular();
	Regular(int _samplesCount);
	Regular(const Regular& right);
	Regular& operator=(const Regular& right);
	virtual Regular* Clone() const;
	virtual ~Regular();

private:
	virtual void GenerateSamples();
};

