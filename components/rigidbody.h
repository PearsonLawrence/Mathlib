#pragma once
#include "vec2.h"
#include "transform.h"
#include "sfwdraw.h"

class RigidBody
{
public:
	RigidBody();
	vec2 acceleration;
	float angularAcceleration;
	vec2 velocity; 
	vec2 force;
	vec2 impulse;

	float torque;
	float angularVelocity;
	void addForce(const vec2 &a_force);
	void addImpulse(const vec2 &impulse);
	void addtorque(float a_torque);
	float mass, drag, angularDrag;
	void debugDraw(const mat3 &t, transform &trans);
	void integrate(transform &trans, float deltatime);
};