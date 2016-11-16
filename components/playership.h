#pragma once
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"

class Gamestate;


class PlayerShip
{

public:
	transform trans;
	Collider collider;
	RigidBody rigidbody;
	spaceshipcontroller controller;
	Spaceshiplocomotion locomotion;
	int health = 100;
	int damage;
	float shootdelay = 1;
	const int maxammo = 5;
	

	PlayerShip();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};