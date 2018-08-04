#include "Hammersley.h"



Hammersley::Hammersley()
	:
	Sampler()
{
}

Hammersley::Hammersley(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

Hammersley::Hammersley(const Hammersley & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

Hammersley & Hammersley::operator=(const Hammersley & right)
{
	if (this == &right)
	{
		return *this;
	}

	Sampler::operator=(right);
	return *this;
}

Hammersley * Hammersley::Clone() const
{
	return new Hammersley(*this);
}


Hammersley::~Hammersley()
{
}

double Hammersley::phi(int j)
{
	return 0.0;
}

void Hammersley::GenerateSamples()
{
	for (int p = 0; p < setsCount; p++)
	{
		for (int j = 0; j < samplesCount; j++)
		{
			Vect2 pv((float)(j / samplesCount), (float)phi(j));
			samples.push_back(pv);
		}
	
	}
}
