#pragma once
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"
#include "spriterenderer.h"
class Gamestate;


class PlayerShip
{

public:
	transform trans;
	Collider collider;
	RigidBody rigidbody;
	spaceshipcontroller controller;
	Spaceshiplocomotion locomotion;
	SpriteRenderer renderer;

	int health = 100;
	int damage;
	int kills = 0;
	int killcounter = 20;
	int ultlvl = 0;
	float shootdelay = 1;
	const int maxammo = 5;
	float time = 3;
	float counter = 0;
	

	PlayerShip();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};