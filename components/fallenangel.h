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
	transform trans, sheildT, sheildt[4], attackT;
	Collider collider, sheildC, sheildc[4], attackC;
	RigidBody rigidbody, sheildR,sheildr[4], attackR;
	Spaceshiplocomotion locomotion, attackL;
	SpriteRenderer renderer, circle, sheild[4],attackRend;
	PlanetaryMotor motor, motor2;
	bool isAlive = false;
	bool attacking = false;
	int health = 40;
	float time = 7;
	Fallen();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};