#pragma once

#include <vector>
#include "Vect2.h"

class Sampler
{
public:
	Sampler();
	~Sampler();

	virtual void GenerateSamples() = 0;
	void SetupShuffledIndices();
	void ShuffleSamples();
	Vect2 SampleUnitSquare();

protected:
	int samplesCount;
	int setsCount;
	std::vector<Vect2> samples;
	std::vector<int> shuffledIndices;
	unsigned long count;
	int jump;
};

