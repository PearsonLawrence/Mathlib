#include "rigidbody.h"

RigidBody::RigidBody()
{
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f;
}

void RigidBody::addForce(const vec2 & force)
{
	acceleration += force;
}

void RigidBody::addImpulse(const vec2 & impulse)
{
	velocity += impulse;
}

void RigidBody::addtorque(float torque)
{
	angularAcceleration += torque;
}

void RigidBody::integrate(transform & trans, float deltatime)
{
	//perform euler integration!
	velocity += acceleration * deltatime;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;

	trans.position = trans.position + velocity * deltatime;
	trans.facing = trans.facing + angularVelocity * deltatime;

}
