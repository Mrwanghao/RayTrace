#include "PureRandom.h"
#include <stdlib.h>
#include "MathUtil.h"
#include <time.h>

PureRandom::PureRandom()
	:
	Sampler()
{
}

PureRandom::PureRandom(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

PureRandom::PureRandom(const PureRandom & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

PureRandom & PureRandom::operator=(const PureRandom & right)
{
	if (this == &right)
	{
		return *this;
	}

	Sampler::operator=(right);
	return *this;
}

PureRandom * PureRandom::Clone() const
{
	return new PureRandom(*this);
}

PureRandom::~PureRandom()
{
}

void PureRandom::GenerateSamples()
{
	srand((unsigned)time(NULL));
	for (int p = 0; p < setsCount; p++)
	{
		for (int q = 0; q < samplesCount; q++)
		{
			samples.push_back(Vect2(RandomFloat(), RandomFloat()));
		}
	}
}
