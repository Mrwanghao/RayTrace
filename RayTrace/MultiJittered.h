#pragma once
#include "Sampler.h"
class MultiJittered : public Sampler
{
public:
	MultiJittered();
	MultiJittered(int _samplesCount);
	MultiJittered(int _samplesCount, int _setsCount);
	MultiJittered(const MultiJittered& right);
	MultiJittered& operator=(const MultiJittered& right);
	virtual MultiJittered* Clone() const;
	virtual ~MultiJittered();

private:
	virtual void GenerateSamples();
};

