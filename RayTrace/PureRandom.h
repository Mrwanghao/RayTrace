#pragma once

#include "Sampler.h"


class PureRandom : public Sampler
{
public:
	PureRandom();
	PureRandom(int _samplesCount);
	PureRandom(const PureRandom& right);
	PureRandom& operator=(const PureRandom& right);
	virtual PureRandom* Clone() const;
	virtual ~PureRandom();

private:
	virtual void GenerateSamples();
};