#include "SpaceshipController.h"

spaceshipcontroller::spaceshipcontroller(unsigned a_CTR_LEFT, unsigned  a_CTR_RIGHT,
	unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT ;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_DOWN;
	CTR_DOWN = a_CTR_UP;
	CTR_BREAK = a_CTR_BREAK;

}

void spaceshipcontroller::update(Spaceshiplocomotion & loco)
{
	float hinput = 0.0f;
	hinput -= sfw::getKey(CTR_RIGHT);
		hinput += sfw::getKey(CTR_LEFT);
		float vinput = 0.0f;
			vinput -= sfw::getKey(CTR_UP);
			vinput += sfw::getKey(CTR_DOWN);
			float binput = sfw::getKey(CTR_BREAK);


			loco.doStop(binput);
			loco.doThrust(vinput);
			loco.doTurn(hinput);

}
