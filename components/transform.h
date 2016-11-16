#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "mat3.h"
class transform
{

public:
	//unsigned s = sfw::loadTextureMap("./res/1.png");
	transform();
	transform(float x, float y,  float vely, float velx, float m_size,  unsigned m_COLOR);
	transform(transform x, transform y, int Up, int down, int left, int right, int sprint, float vely, float velx);

	transform *m_parent;

	vec2 m_position;
	vec2 m_scale;
	vec2 playervelocity{ 0,0 };
	unsigned COLOR = 0;
	float m_facing;
	float size;
	
	int UpKey;
	int DownKey;
	int RightKey;
	int LeftKey;
	int SprintKey;
	float velocity1 = 5;
	float velocity2 = 5;
	//void func(float param1 = 0.0f, float param2);
	vec2 getUp();
	
	mat3 getLocalTransform() const;
	mat3 getGlobalTransform() const;
	vec2 getDirection();

	vec2 getGlobalPosition() const;
	vec2 getGlobalright() const;
	vec2 getGlobalup() const;
	float getGlobalAngle() const;

	void setDirection(const vec2 &dir);
	void debugUpdate();
	void debugDraw(const mat3 &T = mat3identity()) const;



};