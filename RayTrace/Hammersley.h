#pragma once
#include "Sampler.h"
class Hammersley : public Sampler
{
public:
	Hammersley();
	Hammersley(int _samplesCount);
	Hammersley(const Hammersley& right);
	Hammersley& operator=(const Hammersley& right);
	virtual Hammersley* Clone() const;
	virtual ~Hammersley();

public:
	double phi(int j);

private:
	virtual void GenerateSamples();
};


