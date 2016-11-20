#pragma once
#pragma once
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"
#include "spriterenderer.h"
#include "planetarymotor.h"
class Gamestate;

class Fallen
{
public:
	transform trans, sheildT, sheildt[4];
	Collider collider, sheildC, sheildc[4];
	RigidBody rigidbody, sheildR,sheildr[4];
	Spaceshiplocomotion locomotion;
	SpriteRenderer renderer, circle, sheild[4];
	PlanetaryMotor motor, motor2;
	bool isAlive = true;
	int health = 6;
	Fallen();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};