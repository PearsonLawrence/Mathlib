#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "sfwdraw.h"
#include "spriterenderer.h"
#include "planetarymotor.h"
// forward declaration


class Ultimate
{
private:

	unsigned int color = 0;
	float freezeTimer = 2;

public:

	transform trans1,trans2,trans3,trans4,trans5;
	Collider collider1, collider2, collider3,collider4,collider5;
	RigidBody rigid1, rigid2, rigid3,rigid4,rigid5;
	SpriteRenderer renderer1, renderer2, renderer3, renderer4,renderer5;
	PlanetaryMotor motor, motor2, motor3;
	int charge = 0;
	float pressdelay;
	bool isactive = false;
	bool lvl1 = false; 
	bool lvl2 = false;
	bool lvl3 = false;
	bool activate = false;


	Ultimate();
	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);

};
