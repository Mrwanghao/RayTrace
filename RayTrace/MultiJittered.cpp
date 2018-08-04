#include "MultiJittered.h"
#include "MathUtil.h"
#include <time.h>

MultiJittered::MultiJittered()
	:
	Sampler()
{
}

MultiJittered::MultiJittered(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

MultiJittered::MultiJittered(int _samplesCount, int _setsCount)
	:
	Sampler(_samplesCount, _setsCount)
{
	GenerateSamples();
}

MultiJittered::MultiJittered(const MultiJittered & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

MultiJittered & MultiJittered::operator=(const MultiJittered & right)
{
	if (this == &right)
	{
		return *this;
	}

	Sampler::operator=(right);
	return *this;
}

MultiJittered * MultiJittered::Clone() const
{
	return new MultiJittered(*this);
}


MultiJittered::~MultiJittered()
{
}

void MultiJittered::GenerateSamples()
{
	int n = (int)sqrt((float)samplesCount);
	float subcell_width = 1.0 / ((float)samplesCount);

	Vect2 fillPoint;
	for (int j = 0; j < samplesCount * setsCount; j++)
		samples.push_back(fillPoint);

	for (int p = 0; p < setsCount; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				samples[i * n + j + p * samplesCount].x = (i * n + j) * subcell_width + RandomFloat() * subcell_width;
				samples[i * n + j + p * samplesCount].y = (j * n + i) * subcell_width + RandomFloat() * subcell_width;
			}

	for (int p = 0; p < setsCount; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++) {
				int k = rand() % (n - j - 1) + j;
				float t = samples[i * n + j + p * samplesCount].x;
				samples[i * n + j + p * samplesCount].x = samples[i * n + k + p * samplesCount].x;
				samples[i * n + k + p * samplesCount].x = t;
			}

	for (int p = 0; p < setsCount; p++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - 1; j++) {
				int k = rand() % (n - j - 1) + j;
				float t = samples[j * n + i + p * samplesCount].y;
				samples[j * n + i + p * samplesCount].y = samples[k * n + i + p * samplesCount].y;
				samples[k * n + i + p * samplesCount].y = t;
			}
}
