#include "Sampler.h"
#include <algorithm>
#include <time.h>
#include "EngineDefine.h"

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

void Sampler::MapSamplesToUnitDisk()
{
	int size = samples.size();
	float r, phi;
	Vect2 sp;

	diskSamples.reserve(size);

	for (int j = 0; j < size; j++)
	{
		sp.x = 2.0 * samples[j].x - 1.0f;
		sp.y = 2.0 * samples[j].y - 1.0f;

		if (sp.x > -sp.y)
		{
			if (sp.x > sp.y)
			{
				r = sp.x;
				phi = sp.y / sp.x;
			}
			else
			{
				r = sp.y;
				phi = 2 - sp.x / sp.y;
			}
		}
		else
		{
			if (sp.x < sp.y)
			{
				r = -sp.x;
				phi = 4 + sp.y / sp.x;
			}
			else
			{
				r = -sp.y;
				if (sp.y != 0.0f)
				{
					phi = 6 - sp.x / sp.y;
				}
				else
				{
					phi = 0.0f; // �Ƕ����
				}
			}
		}

		phi *= PI / 4.0f;

		diskSamples[j].x = r * cosf(phi);
		diskSamples[j].y = r * sinf(phi);
	}

	samples.erase(samples.begin(), samples.end());
}

Vect2 Sampler::SampleUnitDisk()
{
	srand((unsigned)time(NULL));
	if (count++ % samplesCount == 0)
	{
		jump = (rand() % setsCount) * samplesCount;
	}
	return diskSamples[jump + shuffledIndices[jump + count++ % samplesCount]];
}

void Sampler::MapSamplesToHemisphere(float _exp)
{
	int size = samples.size();
	hemisphereSamples.reserve(samplesCount * setsCount);

	for (int j = 0; j < size; j++)
	{
		float cos_phi = cos(2.0 * PI * samples[j].x);
		float sin_phi = sin(2.0 * PI * samples[j].x);
		float cos_theta = pow((1.0 - samples[j].y), 1.0 / (_exp + 1.0));
		float sin_theta = sqrt(1.0 - cos_theta * cos_theta);
		float pu = sin_theta * cos_phi;
		float pv = sin_theta * sin_phi;
		float pw = cos_theta;
		hemisphereSamples.push_back(Vect3(pu, pv, pw));
	}
	samples.erase(samples.begin(), samples.end());
}

Vect3 Sampler::SampleHemisphere()
{
	srand((unsigned)time(NULL));
	if (count % samplesCount == 0)  									
		jump = (rand() % setsCount) * samplesCount;

	return (hemisphereSamples[jump + shuffledIndices[jump + count++ % samplesCount]]);
}
