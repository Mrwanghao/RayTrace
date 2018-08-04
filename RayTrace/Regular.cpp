#include "Regular.h"



Regular::Regular()
	:
	Sampler()
{
}

Regular::Regular(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

Regular::Regular(const Regular & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

Regular & Regular::operator=(const Regular & right)
{
	if (this == &right)
	{
		return *this;
	}

	Sampler::operator=(right);
	return *this;
}

Regular * Regular::Clone() const
{
	return new Regular(*this);
}


Regular::~Regular()
{
}

void Regular::GenerateSamples()
{
	int n = (int)sqrt((float)samplesCount);
	
	for (int j = 0; j < setsCount; j++)
	{
		for (int p = 0; p < n; p++)
		{
			for (int q = 0; q < n; q++)
			{
				samples.push_back(Vect2((q + 0.5f) / n, (p + 0.5f) / n));
			
			}
		
		}
	}
}
