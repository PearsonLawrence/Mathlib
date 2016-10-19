#include "planetarymotor.h"

void PlanetaryMotor::update(RigidBody & planetRbody)
{
	planetRbody.addtorque(m_rotationSpeed);


}
