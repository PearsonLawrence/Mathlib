#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "camera.h"
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"

#include "spriterenderer.h"

class Map
{
public:
	transform trans;

	Collider collider[6];
	
	SpriteRenderer renderer[4];
	SpriteRenderer render;
	
	Map();

	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);
};
