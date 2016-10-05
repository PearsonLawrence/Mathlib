#pragma once
#include "vec2.h"
#include "transform.h"

class RigidBody
{
public:
	RigidBody();
	vec2 acceleration;
	float angularAcceleration;
	vec2 velocity; 
	float angularVelocity;
	void addForce(const vec2 &force);
	void addImpulse(const vec2 &impulse);
	void addtorque(float torque);

	void integrate(transform &trans, float deltatime);
};