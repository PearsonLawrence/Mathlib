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

float linearHalf(float x)
{
	return 0.5f*x;
}

float slowStart(float x)
{
	return x*x;
}

float fastStart(float x)
{
	return 1 - (1 - x)*(1 - x);
}

float constspeed(float x)
{

	return -abs(2*(x)-1) +1;
}

float bouncetop(float x)
{
	return 1-abs(cos(x*10)*(1-x));
}

float paraFlip(float x)
{
	return -(4*(x*x)) + (4*x) + 0;
}

float lerp(float start, float end, float alpha)
{
	//return (1 - alpha)*start + (alpha*end);

	return alpha*(end - start) + start;
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return lerp(
		lerp(start, mid, alpha),
		lerp(mid, end, alpha),
		alpha);
}

float hermitSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10 * s_tan + h01 * end + h11 * e_tan ;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float tang0 = (mid - start) * tightness;
	float tang1 = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;


	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10 * tang0 + h01 * end + h11 * tang1;
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, .5, alpha);
}

