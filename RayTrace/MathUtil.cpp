#include "MathUtil.h"
#include <stdlib.h>
#include <time.h>

float Clamp(float min, float max, float t)
{
	if (t < min)
	{
		return min;
	}
	else if (t > max)
	{
		return max;
	}
	return t;
}

float RandomFloat()
{
	return (float)rand() / (float)RAND_MAX;
}
