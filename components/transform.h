#pragma once
#include "vec2.h"


class transform
{

public:
	transform();
	transform(float x, float y, int Up, int down, int left, int right, int sprint);
	transform(transform x, transform y, int Up, int down, int left, int right, int sprint);

	vec2 position;
	vec2 scale;
	float facing;
	int UpKey;
	int DownKey;
	int RightKey;
	int LeftKey;
	int SprintKey;
	vec2 getDirection();
	void serDirection(const vec2 &dir);
	void debugUpdate();
	void debugDraw();


};