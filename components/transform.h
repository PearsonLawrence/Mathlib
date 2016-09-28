#pragma once
#include "vec2.h"


class transform
{

public:
	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection();
	void serDirection(const vec2 &dir);

	void debugDraw();


};