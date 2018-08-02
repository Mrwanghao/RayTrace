#include "Sampler.h"
#include <algorithm>


Sampler::Sampler()
	:
	samplesCount(1),
	setsCount(83),
	count(0),
	jump(1)
{
	samples.reserve(samplesCount * setsCount);
	this->SetupShuffledIndices();
}


Sampler::~Sampler()
{
}

void Sampler::GenerateSamples()
{
}

void Sampler::SetupShuffledIndices()
{
	//shuffled_indices.reserve(num_samples * num_sets);
	//vector<int> indices;
	//
	//for (int j = 0; j < num_samples; j++)
	//	indices.push_back(j);
	//
	//for (int p = 0; p < num_sets; p++) {
	//	random_shuffle(indices.begin(), indices.end());
	//
	//	for (int j = 0; j < num_samples; j++)
	//		shuffled_indices.push_back(indices[j]);
	//}
	shuffledIndices.reserve(samplesCount * setsCount);
	std::vector<int> indices;

	for (int j = 0; j < samplesCount; j++)
	{
		indices.push_back(j);
	}

	for (int p = 0; p < setsCount; p++)
	{
		

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
	return Vect2();
}
