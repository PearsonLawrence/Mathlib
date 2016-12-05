#pragma once
#include "transform.h"


class Camera
{
public:
	float scalenum = 10.0f;
	mat3 ScaleC = scale(scalenum, scalenum);
	mat3 projection;
	transform Transform;

	
	Camera();


	mat3 getCameraMatrix();

	void update(float deltatime, class Gamestate &gs);

};