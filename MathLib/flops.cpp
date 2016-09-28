#include "flops.h"

#define _USE_MATH_DEFINES

#include <cfloat>
#include <cmath>
bool fequals(float lhs, float rhs)
{
	
	if (fabs(lhs - rhs) <= 0.00001)
	{
		return true;
	}
		return false;
}

float deg2rad(float deg)
{
	return deg * M_PI / 180.f;
}

float rad2deg(float rad)
{

	return rad*(180 / M_PI);
}