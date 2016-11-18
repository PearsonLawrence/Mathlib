#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "sfwdraw.h"
#include "spriterenderer.h"
// forward declaration


class Bomb
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
	bool explode = false;
	int bombcount;

	Bomb();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};
