#include "gamestate.h"

void Gamestate::init()
{
	player.trans.m_position = vec2{ 200,200 };
	player.trans.m_facing = 0;
}

void Gamestate::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);

}

void Gamestate::draw()
{
	mat3 cam = camera.getCameraMatrix();

	player.draw(cam);
}
