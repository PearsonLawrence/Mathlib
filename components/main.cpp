#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
#include "flops.h"
#include "rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipController.h"
#include "planetarymotor.h"
#include "planetaryRender.h"
#include "shipRender.h"
#include "shapedraw.h"
#include "collider.h"
#include "collision.h"
#include "gamestate.h"
int main()
{
	//unsigned s = sfw::loadTextureMap("./components/res/wall.jpg");
	//sfw::drawTexture(s, 0, 0, 1600, 900);
	sfw::initContext(1600, 900);
	
	Gamestate game;

	game.play();


	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		

		game.update(dt);
		game.draw();

	}

	sfw::termContext();

	getchar();

}