#pragma once
#include "rigidbody.h"
#include "sfwdraw.h"
class Spaceshiplocomotion
{
	

	float vertthrust;            //forward movement 0 - 1 value
	float horzthrust;         // max forward movement
	

	float turn;              //turn -1 to 1
	float maxturn;           // max turn
	float turnSpeed;         // rate of change for our turn

	float speed;      
	float maxspeed;// movement speed

public:
	Spaceshiplocomotion();
	void doThrust(float value);
	void doTurn(float value);

	void integrate(RigidBody &rigidbody, float deltaTime);
	
};