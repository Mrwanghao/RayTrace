#include "MathUtil.h"
#include <stdlib.h>
#include <math.h>
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

Vect3 ColorToMaxOne(const Vect3 & color)
{
	if (color.x > 1.0f || color.y > 1.0f || color.z > 1.0f)
	{
		Vect3 result;
		float max = fmaxf(color.x, fmaxf(color.y, color.z));
		result = color / max;
		return result;
	}
	return color;
}

float RandomFloat()
{
	return (float)rand() / (float)RAND_MAX;
}


