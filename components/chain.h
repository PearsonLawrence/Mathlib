#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "sfwdraw.h"
#include "spriterenderer.h"
// forward declaration


class Chain
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
	float shoottime;
	bool chainactive = false;
	PlayerShip * instigator;

	int id;

	vec2 a, b;

	Chain();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};
