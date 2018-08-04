#include "NRooks.h"
#include "MathUtil.h"


NRooks::NRooks()
	:
	Sampler()
{
}

NRooks::NRooks(int _samplesCount)
	:
	Sampler(_samplesCount)
{
	GenerateSamples();
}

NRooks::NRooks(const NRooks & right)
	:
	Sampler(right)
{
	GenerateSamples();
}

NRooks & NRooks::operator=(const NRooks & right)
{
	if (this == &right)
		return (*this);

	Sampler::operator=(right);

	return (*this);
}

NRooks * NRooks::Clone() const
{
	return new NRooks(*this);
}


NRooks::~NRooks()
{
}

void NRooks::GenerateSamples()
{
	for (int p = 0; p < setsCount; p++)
		for (int j = 0; j < samplesCount; j++) {
			Vect2 sp((j + RandomFloat()) / samplesCount, (j + RandomFloat()) / samplesCount);
			samples.push_back(sp);
		}

	ShuffleXCoordinantes();
	ShuffleYCoordinantes();
}
