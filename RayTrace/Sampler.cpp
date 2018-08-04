#include "Sampler.h"
#include <algorithm>
#include <time.h>


Sampler::Sampler()
	:
	samplesCount(1),
	setsCount(83),
	count(0),
	jump(0)
{
	samples.reserve(samplesCount * setsCount);
	this->SetupShuffledIndices();
}

Sampler::Sampler(int _samplesCount)
	:
	samplesCount(_samplesCount),
	setsCount(83),
	count(0),
	jump(0)
{
	samples.reserve(samplesCount * setsCount);
	this->SetupShuffledIndices();
}

Sampler::Sampler(int _samplesCount, int _setsCount)
	:
	samplesCount(_samplesCount),
	setsCount(_setsCount),
	count(0),
	jump(0)
{
	samples.reserve(samplesCount * setsCount);
	this->SetupShuffledIndices();
}

Sampler::Sampler(const Sampler & right)
	:
	samplesCount(right.samplesCount),
	setsCount(right.setsCount),
	samples(right.samples),
	shuffledIndices(right.shuffledIndices),
	count(right.count),
	jump(right.jump)
{
}

Sampler::~Sampler()
{
}

Sampler & Sampler::operator=(const Sampler & right)
{
	if (&right == this)
	{
		return *this;
	}

	samplesCount = right.samplesCount;
	setsCount = right.setsCount;
	samples = right.samples;
	shuffledIndices = right.shuffledIndices;
	count = right.count;
	jump = right.jump;

	return *this;
}

void Sampler::SetupShuffledIndices()
{
	shuffledIndices.reserve(samplesCount * setsCount);
	std::vector<int> indices;

	for (int j = 0; j < samplesCount; j++)
	{
		indices.push_back(j);
	}

	for (int p = 0; p < setsCount; p++)
	{
		random_shuffle(indices.begin(), indices.end());
		for (int j = 0; j < samplesCount; j++)
		{
			shuffledIndices.push_back(indices[j]);
		}
	}
}

void Sampler::ShuffleSamples()
{
}

Vect2 Sampler::SampleUnitSquare()
{
	srand((unsigned)time(NULL));
	if (count % samplesCount == 0)
	{
		jump = (rand() % setsCount) * samplesCount;
	}

	return samples[jump + shuffledIndices[jump + count++ % samplesCount]];
}

Vect2 Sampler::SampleOneSet()
{
	return samples[count++ % samplesCount];
}

void Sampler::ShuffleXCoordinantes()
{
	srand((unsigned)time(NULL));
	for (int p = 0; p < setsCount; p++)
	{
		for (int i = 0; i < samplesCount - 1; i++)
		{
			
			int target = rand() % samplesCount + p * samplesCount;

			float temp = samples[i + p * samplesCount + 1].x;
			samples[i + p * samplesCount + 1].x = samples[target].x;
			samples[target].x = temp;
		}
	}
}

void Sampler::ShuffleYCoordinantes()
{
	srand((unsigned)time(NULL));
	for (int p = 0; p < setsCount; p++)
	{
		for (int i = 0; i < samplesCount - 1; i++)
		{

			int target = rand() % samplesCount + p * samplesCount;

			float temp = samples[i + p * samplesCount + 1].y;
			samples[i + p * samplesCount + 1].y = samples[target].y;
			samples[target].y = temp;
		}
	}
}
