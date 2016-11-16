#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "camera.h"
#include "transform.h"
#include "collider.h"
#include "rigidbody.h"
#include "SpaceshipController.h"
#include "spaceshiplocomotion.h"

class Map
{
public:
	//unsigned s = sfw::loadTextureMap("./components/res/wall.jpg");

	transform trans;

	Collider collider[4];
	
	
	
	

	Map();

	void update(float deltatime, class Gamestate &gs);
	void draw(const mat3 &camera);
	void mapDraw(const mat3 & camera);

};
