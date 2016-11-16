#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "sfwdraw.h"

	// forward declaration


class Bullet
{
private:
	
	unsigned int color = 0;
	float freezeTimer = 2;

public:

	transform trans;
	Collider collider;
	Spaceshiplocomotion loco;
	RigidBody rigidbody;
	bool isactive = false;
	float shoottime;

	Bullet();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};