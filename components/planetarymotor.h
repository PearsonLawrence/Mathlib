#pragma once
#include "rigidbody.h"

class PlanetaryMotor
{
public:
	float m_rotationSpeed;

	void update(RigidBody &planetRbody);

};