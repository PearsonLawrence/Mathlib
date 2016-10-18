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
	





	transform trans(400, 200,  5, 5);
	transform wrist(2, 0, 5, 5);
	transform elbow(20, 0, 5, 5);

	
	RigidBody playerRigidbody;
	RigidBody elbowrigidbody;
	RigidBody wristrigidbody;
	elbow.m_parent = &trans;
	wrist.m_parent = &elbow;
	//transform wrist(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT, 5, 5);
	

	
	

	

	vec2 start = { 100,100 },
		end = { 200,600 },
		mid = { 600,200 },
		e_tan = { 200, 0},
		s_tan = { 400, 200 };
	Spaceshiplocomotion playerShoulder;
	spaceshipcontroller shoulderctrl('A', 'D', ' ', ' ', ' ');
	Spaceshiplocomotion playerElbow;
	spaceshipcontroller elbowctrl('F', 'H', ' ', ' ', ' ');
	Spaceshiplocomotion playerWrist;
	spaceshipcontroller wristctrl('J', 'L', ' ', ' ', ' ');
	vec2 basis = { 40, 0};
	float steps = 100;
	float ang_vec = 0;
	while (sfw::stepContext())
	{
		float deltatime = sfw::getDeltaTime();

		// all the updates
		shoulderctrl.update(playerShoulder);
		playerShoulder.integrate(elbow, playerRigidbody, deltatime);
		playerRigidbody.integrate(trans, deltatime);

		elbowctrl.update(playerElbow);
		playerElbow.integrate(elbow, elbowrigidbody, deltatime);
		elbowrigidbody.integrate(elbow, deltatime);

		wristctrl.update(playerWrist);
		playerWrist.integrate(wrist, wristrigidbody, deltatime);
		wristrigidbody.integrate(wrist, deltatime);

		trans.debugUpdate();
		

		// all the draws
	
		playerRigidbody.debugDraw(trans);
		elbowrigidbody.debugDraw(elbow);
		elbowrigidbody.debugDraw(wrist);

		trans.debugDraw();
		wrist.debugDraw();
		elbow.debugDraw();
		

		//elbow.debugUpdate(trans.getLocalTransform);
		
		
	
		
	}

	sfw::termContext();

	getchar();

}