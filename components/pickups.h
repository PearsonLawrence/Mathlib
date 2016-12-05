#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "sfwdraw.h"
#include "spriterenderer.h"
// forward declaration


class Pickup
{
private:

	unsigned int color = 0;
	float freezeTimer = 2;

public:

	transform trans;
	Collider collider;
	Spaceshiplocomotion loco;
	RigidBody rigidbody;
	SpriteRenderer renderer;
	bool isactive = false;
	class Bomb * instigator;

	

	vec2 a, b;

	Pickup();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);
};