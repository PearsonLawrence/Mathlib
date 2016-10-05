#pragma once
#include "vec2.h"
#include "sfwdraw.h"

class transform
{

public:
	//unsigned s = sfw::loadTextureMap("./res/1.png");
	transform();
	transform(float x, float y, int Up, int down, int left, int right, int sprint, float vely, float velx);
	transform(transform x, transform y, int Up, int down, int left, int right, int sprint, float vely, float velx);

	vec2 position{ 200, 200 };
	vec2 scale;
	vec2 playervelocity{ 0,0 };
	float facing;
	int UpKey;
	int DownKey;
	int RightKey;
	int LeftKey;
	int SprintKey;
	float velocity1 = 5;
	float velocity2 = 5;
	//void func(float param1 = 0.0f, float param2);
	vec2 getUp();

	vec2 getDirection();
	void serDirection(const vec2 &dir);
	void debugUpdate();
	void debugDraw();


};