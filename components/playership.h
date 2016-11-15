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

	PlayerShip();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};