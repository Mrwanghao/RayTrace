#pragma once

#include <vector>
#include "Vect2.h"
#include "Vect3.h"

class Sampler
{
public:
	Sampler();
	Sampler(int _samplesCount);
	Sampler(int _samplesCount, int _setsCount);
	Sampler(const Sampler& right);
	virtual ~Sampler();

public:
	Sampler & operator=(const Sampler& right);

public:
	virtual void GenerateSamples() = 0;
	virtual Sampler* Clone() const = 0;
	void SetupShuffledIndices();
	void ShuffleSamples();
	Vect2 SampleUnitSquare();
	Vect2 SampleOneSet();
	void ShuffleXCoordinantes();
	void ShuffleYCoordinantes();
	void MapSamplesToUnitDisk();
	Vect2 SampleUnitDisk();
	void MapSamplesToHemisphere(float _exp);
	Vect3 SampleHemisphere();

public:
	inline void SetSetsCount(int _setsCount) { setsCount = _setsCount; }
	inline int GetSetsCount() { return setsCount; }
	inline void SetSamplesCount(int _samplesCount) { samplesCount = _samplesCount; }
	inline int GetSamplesCount() { return samplesCount; }

protected:
	int samplesCount;
	int setsCount;
	std::vector<Vect2> samples;
	std::vector<int> shuffledIndices;
	std::vector<Vect2> diskSamples;
	std::vector<Vect3> hemisphereSamples;
	unsigned long count;
	int jump;
};

