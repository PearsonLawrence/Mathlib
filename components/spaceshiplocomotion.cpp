#include "spaceshiplocomotion.h"
#include "rigidbody.h"

Spaceshiplocomotion::Spaceshiplocomotion()
{
	vertthrust = 0;  // forward movement 0-1 value
	horzthrust = 0.0f; // max forward movement
	maxspeed = 300.0f;
	turn = 0.0f;  // turn -1 - 1 value
	maxturn = 300.0f; // max turn
	turnSpeed = 1.0f; // rate of change for our turn

	speed = 200.0f; // movement speed
}

void Spaceshiplocomotion::doThrust(float value)
{

	vertthrust = value;


}

void Spaceshiplocomotion::doTurn(float value)
{
	horzthrust = value;
}

void Spaceshiplocomotion::integrate(RigidBody & rigidbody, float deltaTime)
{
	// apply the values to my rigidbody
//	doThrust();
//	doTurn();
	//if (rigidbody.velocity.y <= 0 && rigidbody.acceleration.y < 50) {rigidbody.velocity.y = 0;}
	rigidbody.acceleration.y = vertthrust * speed;
	rigidbody.acceleration.x = horzthrust * speed;

	if (magnitude(rigidbody.velocity) > maxspeed)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxspeed;
	}


	//if (rigidbody.velocity.x > 200.0f) rigidbody.velocity.x = 200.0f;
	//if (rigidbody.velocity.x < -200.0f) rigidbody.velocity.x = -200.0f;
	//if (rigidbody.velocity.y > 200.0f) rigidbody.velocity.y = 200.0f;
	//if (rigidbody.velocity.y < -200.0f) rigidbody.velocity.y = -200.0f;


	// zero out the thrust values
	vertthrust = 0.0f;
	horzthrust = 0.0f;
}
