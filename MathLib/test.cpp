// this is ther develop branch..
#include <math.h>
#include "test.h"

int doNothing(int x)
{
	return x*x + 2 * x + 5;

}

float test_quad(float x) 
{
	return x*x + 2 * x - 7;

}

float Quad_eqatePlus(float a, float b, float c)
{
	return ((-b + sqrt(b*b - 4 * a*c)) / (2 * a));
}

float Quad_eqateMinus(float a, float b, float c)
{
	return ((-b - sqrt(b*b - 4 * a*c)) / (2 * a));
}

float blend(float s, float e, float t)
{
	return (s + t*(e-s));
}

float pointdist(float x, float y, float x2, float y2)
{

	return sqrt((x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
}

float inner(float x, float y, float z, float x2, float y2, float z2)
{
	return x*x2 + y*y2 + z*z2;
}


//Quad Quad_equat(float a, float b, float c)
//{
//	
//	float x1 = ((-b + sqrt(b*b - 4 * a*c)) / (2 * a));
//	float x2 = ((-b - sqrt(b*b - 4 * a*c)) / (2 * a));
//	return x1, x2;
//}