#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
#include "flops.h"
#include "rigidbody.h"
#include "spaceshiplocomotion.h"
#include "SpaceshipController.h"
#include "planetarymotor.h"
#include "planetaryRender.h"

int main()
{
	unsigned s = sfw::loadTextureMap("./res/1.png");

	sfw::initContext(800, 600);
	




	transform sun(400, 300, 5, 5,20, YELLOW);
	transform sun2(400, 300, 5, 5, 20, YELLOW);
	transform sun3(400, 300, 5, 5, 20, YELLOW);
	transform sun4(400, 300, 5, 5, 20, YELLOW);
	transform sun5(400, 300, 5, 5, 20, YELLOW);

	transform trans(400, 200,  5, 5, 20, RED);
	transform wrist1(0, -0.1f, 5, 5, 20, RED);
	transform Shoulder(10, 0, 5, 5, 20, RED);
	transform elbow(0, -1, 5, 5, 20, RED);
	transform wrist2(0, -0.1f, 5, 5, 10, RED);
	transform Shoulder2(-10, 0, 5, 5,  10, RED);
	transform elbow2(0, -1, 5, 5,  10, RED);
	transform Earth(10, 1, 5, 5, 10, GREEN);
	transform Mars(15, 2,5,5, 10, RED);
	transform jupiter(20, 3, 5, 5, 10, RED);
	transform saturn(25, 4, 5, 5, 10, CYAN);
	transform venus(5, 0, 5, 5, 10, BLACK);
	transform moon1(.35, 0, 5, 5, 5, WHITE);

	RigidBody playerRigidbody;
	RigidBody elbowrigidbody;
	RigidBody wristrigidbody;
	RigidBody shoulderRigidbody;
	RigidBody elbow2rigidbody;
	RigidBody wrist2rigidbody;
	RigidBody shoulder2Rigidbody;
	RigidBody sunBody;
	PlanetaryMotor sunmotor;
	sunmotor.m_rotationSpeed = 1.1;
	RigidBody sunBody2;
	PlanetaryMotor sunmotor2;
	sunmotor2.m_rotationSpeed = 1;

	RigidBody sunBody3;
	PlanetaryMotor sunmotor3;
	sunmotor3.m_rotationSpeed = .80;

	RigidBody sunBody4;
	PlanetaryMotor sunmotor4;
	sunmotor4.m_rotationSpeed = .75;

	RigidBody sunBody5;
	RigidBody EarthBody;
	PlanetaryMotor sunmotor5;
	PlanetaryMotor Earthmotor;
	sunmotor5.m_rotationSpeed = .70;
	Earthmotor.m_rotationSpeed = 4;



	Earth.m_parent = &sun;
	moon1.m_parent = &Earth;
	Mars.m_parent = &sun2;
	venus.m_parent = &sun3;
	jupiter.m_parent = &sun4;
	saturn.m_parent = &sun5;
	Shoulder.m_parent = &trans;
	elbow.m_parent = &Shoulder;
	wrist1.m_parent = &elbow;
	Shoulder2.m_parent = &trans;
	elbow2.m_parent = &Shoulder2;
	wrist2.m_parent = &elbow2;
	
	
	//transform wrist(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT, 5, 5);
	

	
	

	

	vec2 start = { 100,100 },
		end = { 200,600 },
		mid = { 600,200 },
		e_tan = { 200, 0},
		s_tan = { 400, 200 };
	/*Spaceshiplocomotion playerskell;
	spaceshipcontroller skelcontroller(KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, ' ');*/
	Spaceshiplocomotion playerShoulder;
	spaceshipcontroller shoulderctrl('A', 'D', ' ', ' ', ' ');
	Spaceshiplocomotion playerElbow;
	spaceshipcontroller elbowctrl('F', 'H', ' ', ' ', ' ');
	Spaceshiplocomotion playerWrist1;
	spaceshipcontroller wristctrl1('J', 'L', ' ', ' ', ' ');
	Spaceshiplocomotion playerShoulder2;
	spaceshipcontroller shoulderctrl2('Q', 'E', ' ', ' ', ' ');
	Spaceshiplocomotion playerElbow2;
	spaceshipcontroller elbowctrl2('R', 'Y', ' ', ' ', ' ');
	Spaceshiplocomotion playerWrist2;
	spaceshipcontroller wristctrl2('U', 'O', ' ', ' ', ' ');

	vec2 basis = { 40, 0};
	float steps = 100;
	float ang_vec = 0;
	while (sfw::stepContext())
	{
		float deltatime = sfw::getDeltaTime();

		sunmotor.update(sunBody);
		Earthmotor.update(EarthBody);
		sunmotor2.update(sunBody2);
		sunmotor3.update(sunBody3);
		sunmotor4.update(sunBody4);
		sunmotor5.update(sunBody5);
		sunBody.integrate(sun, deltatime);
		EarthBody.integrate(Earth, deltatime);
		sunBody2.integrate(sun2, deltatime);
		sunBody3.integrate(sun3, deltatime);
		sunBody4.integrate(sun4, deltatime);
		sunBody5.integrate(sun5, deltatime);
		sun.debugDraw();
		sun2.debugDraw();
		sun3.debugDraw();
		sun4.debugDraw();
		sun5.debugDraw();



		Earth.debugDraw();
		Mars.debugDraw();
		saturn.debugDraw();
		jupiter.debugDraw();
		venus.debugDraw();
		moon1.debugDraw();








		// all the updates
		/*skelcontroller.update(playerskell);
		playerskell.integrate(trans, playerRigidbody, deltatime);
		playerRigidbody.integrate(trans, deltatime);*/


		//shoulderctrl.update(playerShoulder);
		//playerShoulder.integrate(Shoulder, shoulderRigidbody, deltatime);
		//shoulderRigidbody.integrate(Shoulder, deltatime);

		//elbowctrl.update(playerElbow);
		//playerElbow.integrate(elbow, elbowrigidbody, deltatime);
		//elbowrigidbody.integrate(elbow, deltatime);

		//wristctrl1.update(playerWrist1);
		//playerWrist1.integrate(wrist1, wrist2rigidbody, deltatime);
		//wristrigidbody.integrate(wrist1, deltatime);

		//	shoulderctrl2.update(playerShoulder2);
		//playerShoulder2.integrate(Shoulder2, shoulder2Rigidbody, deltatime);
		//shoulder2Rigidbody.integrate(Shoulder2, deltatime);

		//elbowctrl2.update(playerElbow2);
		//playerElbow2.integrate(elbow2, elbow2rigidbody, deltatime);
		//elbow2rigidbody.integrate(elbow2, deltatime);

		//wristctrl2.update(playerWrist2);
		//playerWrist2.integrate(wrist2, wrist2rigidbody, deltatime);
		//wrist2rigidbody.integrate(wrist2, deltatime);

		//trans.debugUpdate();
		//

		//// all the draws
	
		//playerRigidbody.debugDraw(trans);
		//elbowrigidbody.debugDraw(elbow);
		//elbowrigidbody.debugDraw(wrist1);

		//trans.debugDraw();
		//wrist1.debugDraw();
		//elbow.debugDraw();
		//Shoulder.debugDraw();
		//wrist2.debugDraw();
		//elbow2.debugDraw();
		//Shoulder2.debugDraw();

		//elbow.debugUpdate(trans.getLocalTransform);
		
		
		// position of tank after all transformations
		mat3 testTrans = translate(-6, 9) * rotate(deg2rad(253.047f));	// to start pos and rot
		
		vec2 pos = testTrans[2].xy;

		// desired direction to face target
		vec2 desiredDir = (vec2{ -22,-5 } - pos);
		vec2 currentDir = fromAngle(deg2rad(253.047f));

		float rotDelta = angleBetween(desiredDir, currentDir);	// necessary angle of rotation
		
		testTrans = testTrans * rotate(-rotDelta) * translate(magnitude(desiredDir),0);

		pos = testTrans[2].xy;

		printf("YEAHSON");
		
	}

	sfw::termContext();

	getchar();

}