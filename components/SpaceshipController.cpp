#include "SpaceshipController.h"

void spaceshipcontroller::update(Spaceshiplocomotion & loco)
{
	float hinput = 0.0f;
	hinput -= sfw::getKey('A');
		hinput += sfw::getKey('D');
		float vinput = 0.0f;
			vinput -= sfw::getKey('S');
			vinput += sfw::getKey('W');

			loco.doThrust(vinput);
			loco.doTurn(hinput);

}
