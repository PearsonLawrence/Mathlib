#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
#include "flops.h"
#include "rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipController.h"

int main()
{
	unsigned s = sfw::loadTextureMap("./res/1.png");

	sfw::initContext(800, 600);
	
	transform trans(400, 200, 'W', 'S', 'D', 'A', KEY_RIGHT_SHIFT, 5, 5);

	RigidBody playerRigidbody;

	//transform tranz(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT, 5, 5);
	
	trans.m_position = vec2{ 400,300 };
	trans.m_facing = 0;
	trans.m_scale = vec2{ 12,8 };
	vec2 start = { 100,100 },
		end = { 200,600 },
		mid = { 600,200 },
		e_tan = { 200, 0},
		s_tan = { 400, 200 };
	Spaceshiplocomotion playerLoco;
	spaceshipcontroller playerctrl;
	vec2 basis = { 40, 0};
	float steps = 100;
	float ang_vec = 0;
	while (sfw::stepContext())
	{
		float deltatime = sfw::getDeltaTime();

		playerRigidbody.integrate(trans, deltatime);
		playerLoco.integrate(trans, playerRigidbody, deltatime);
		trans.debugDraw();
		trans.debugUpdate();
		playerctrl.update(playerLoco);
		playerRigidbody.debugDraw(trans);
		
		
	}

	sfw::termContext();

	getchar();

}