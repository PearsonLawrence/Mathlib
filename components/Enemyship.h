#pragma once
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"
#include "spriterenderer.h"
class Gamestate;

class EnemyShip
{
public:
	transform trans;
	Collider collider;
	RigidBody rigidbody;
	Spaceshiplocomotion locomotion;
	SpriteRenderer renderer;

	int health = 6;
	EnemyShip();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

	bool isAlive();
	void onDeath();
};