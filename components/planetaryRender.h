#pragma once
#include "transform.h"
class PlanetaryRender
{
public:
	PlanetaryRender(unsigned a_color = 0xffffffff, float a_size = 20.f);

	unsigned int color;
	float size;

	void draw(transform &planetTrans);


};