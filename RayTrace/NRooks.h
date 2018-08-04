#pragma once
#include "Sampler.h"
class NRooks : public Sampler
{
public:
	NRooks();
	NRooks(int _samplesCount);
	NRooks(const NRooks& right);
	NRooks& operator=(const NRooks& right);
	virtual NRooks* Clone() const;
	virtual ~NRooks();

private:
	virtual void GenerateSamples();
};

