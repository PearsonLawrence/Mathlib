#pragma once
#include <math.h>
int doNothing(int x);

float test_quad(float x);

struct point
{
	float x = 0, y = 0;
};


struct Quad
{
	float Plus, Minus;
	float roots;
};

//Quad Quad_equat(float a, float b, float c);

float Quad_eqatePlus(float a, float b, float c);
float Quad_eqateMinus(float a, float b, float c);


float blend(float s, float e, float t);
//


float pointdist(float x, float y, float x2, float y2);

float inner(float x, float y, float z, float x2, float y2, float z2);