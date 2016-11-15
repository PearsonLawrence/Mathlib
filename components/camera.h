#pragma once
#include "transform.h"


class Camera
{
public:
	mat3 projection;
	transform Transform;
	
	Camera();


	mat3 getCameraMatrix();

	void update(float deltatime, class Gamestate &gs);

};