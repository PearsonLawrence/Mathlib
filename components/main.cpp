#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
#include "flops.h"
#include "rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipController.h"

int main()
{
	

	sfw::initContext(800, 600);
	
	transform trans(400, 200, 'W', 'S', 'D', 'A', KEY_RIGHT_SHIFT, 5, 5);
	//transform trans2;
	RigidBody playerRigidbody;

	//transform tranz(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT, 5, 5);
	
	trans.position = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 12,8 };
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
		float deltatime = sfw::getDeltaTime();/*

		if (sfw::getKey('W')) playerRigidbody.acceleration.y += 50.0f;
		if (sfw::getKey('S')) playerRigidbody.acceleration.y -= 50.0f;
		if (sfw::getKey('A')) playerRigidbody.acceleration.x -= 50.0f;
		if (sfw::getKey('D')) playerRigidbody.acceleration.x += 50.0f;
		if (sfw::getKey('Q')) playerRigidbody.angularAcceleration += 1.0f;

		if (sfw::getKey('E')) playerRigidbody.angularAcceleration -= 1.0f;
*/


	
		

	/*	if (playerRigidbody.velocity.x > 200.0f) playerRigidbody.velocity.x = 200.0f;
		if (playerRigidbody.velocity.x < -200.0f) playerRigidbody.velocity.x = -200.0f;
		if (playerRigidbody.velocity.y > 200.0f) playerRigidbody.velocity.y = 200.0f;
		if (playerRigidbody.velocity.y < -200.0f) playerRigidbody.velocity.y = -200.0f;
*/

		playerRigidbody.integrate(trans, deltatime);
		playerLoco.integrate(playerRigidbody, deltatime);
		trans.debugDraw();
		trans.debugUpdate();
		playerctrl.update(playerLoco);

		/*float size = 100;
		for (int i = 0; i < size; ++i)
		{
			float t1 = i / steps;
			float t2 = (i + 1) / steps;


			vec2 v1 = catRomSpline(start, mid, end, t1);
			vec2 v2 = catRomSpline(start, mid, end, t2);

			sfw::drawLine(v1.x, v1.y, v2.x, v2.y);

		}*/
		
	/*	ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, normal(incident));

		sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);
		sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, CYAN);
		sfw::drawLine(400, 300, 400 + proj, 300, GREEN);*/
		
		//trans2.position = trans.position - trans.getDirection() * 25.f;

		//trans2.facing = trans.position.x && trans.position.y;

		
		//trans2.debugUpdate();
		//tranz.debugUpdate();
		
		//trans.debugDraw();
		//trans2.debugDraw();
		//tranz.debugDraw();
		
		
	}

	sfw::termContext();

	getchar();

}