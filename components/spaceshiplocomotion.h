#pragma once
#include "rigidbody.h"
#include "sfwdraw.h"
class Spaceshiplocomotion
{
	
public:
	float vertthrust;            //forward movement 0 - 1 value
	float horzthrust;         // max forward movement
	float breakpower;
	float stopAction;

	float turn;              //turn -1 to 1
	float maxturn;           // max turn
	float turnSpeed;         // rate of change for our turn

	float speed;      
	float maxspeed;// movement speed


	Spaceshiplocomotion();
	void doThrust(float value);
	void doTurn(float value);
	void doStop(float value);
	void integrate(transform &trans, RigidBody &rigidbody, float deltaTime);
	
};