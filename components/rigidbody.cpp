#include "rigidbody.h"

RigidBody::RigidBody()
{
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	mass = 1;
	drag = .75;
	torque = 0;
	angularDrag = 1;

}

void RigidBody::addForce(const vec2 & a_force)
{
	force += a_force;
}

void RigidBody::addImpulse(const vec2 & a_impulse)
{
	impulse += a_impulse;
}

void RigidBody::addtorque(float a_torque)
{
	torque += a_torque;
}

void RigidBody::debugDraw(transform & trans)
{
	vec2 p = trans.position;
	vec2 v = p + velocity;
	vec2 a = acceleration + v;

	sfw::drawLine(p.x, p.y, v.x, v.y, CYAN);
	sfw::drawLine(p.x, p.y, a.x, a.y, MAGENTA);
}

void RigidBody::integrate(transform & trans, float deltatime)
{
	//perform euler integration!
	acceleration = force / mass;
	velocity += acceleration * deltatime + impulse / mass;
	trans.position += velocity * deltatime;
	force = impulse = { 0,0 };

	force = -velocity * drag;

	
	angularAcceleration = torque / mass;
	angularVelocity = angularVelocity + angularAcceleration * deltatime;
	trans.facing = trans.facing + angularVelocity * deltatime;
	torque = 0;
	torque = -angularVelocity * angularDrag;

}
