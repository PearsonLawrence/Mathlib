#pragma once
#include "transform.h"
#include "collider.h"

class Gamestate;

class AttackArea
{

public:
	transform trans;
	Collider collider;

	AttackArea();

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 & camera);

};