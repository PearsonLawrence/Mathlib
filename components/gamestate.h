#pragma once

#include "playership.h"
#include "camera.h"

class Gamestate
{
public:

	PlayerShip player;
	Camera camera;

	void init();
	void update(float deltaTime);
	void draw();

};