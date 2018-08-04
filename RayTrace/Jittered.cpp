#include "Jittered.h"
#include "MathUtil.h"
#include <time.h>

Jittered::Jittered()
	:
	Sampler()
{
}

Jittered::Jittered(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

Jittered::Jittered(int _samplesCount, int _setsCount)
	:
	Sampler(_samplesCount, _setsCount)
{
	GenerateSamples();
}

Jittered::Jittered(const Jittered & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

Jittered & Jittered::operator=(const Jittered & right)
{
	if (this == &right)
	{
		return *this;
	}

	Sampler::operator=(right);
	return *this;
}

Jittered * Jittered::Clone() const
{
	return new Jittered(*this);
}


Jittered::~Jittered()
{
}

void Jittered::GenerateSamples()
{
	int n = (int)sqrt(samplesCount);
	srand((unsigned)time(NULL));
	for (int p = 0; p < setsCount; p++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Vect2 sample((k + RandomFloat()) / n, (j + RandomFloat()) / n);
				samples.push_back(sample);
			}
		}
	}


}
