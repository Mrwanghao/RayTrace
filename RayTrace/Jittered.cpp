#include "Jittered.h"



Jittered::Jittered()
{
}


Jittered::~Jittered()
{
}

void Jittered::GenerateSamples()
{
	int n = (int)sqrt(samplesCount);

	for (int p = 0; p < setsCount; p++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				Vect2 sample((k + rand()) / n, (j + rand()) / n);
				samples.push_back(sample);
			}
		}
	}


}
