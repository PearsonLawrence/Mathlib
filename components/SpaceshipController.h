#pragma once
#include "spaceshiplocomotion.h"
class spaceshipcontroller
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	spaceshipcontroller(unsigned a_CTR_LEFT , unsigned  a_CTR_RIGHT ,
		unsigned a_CTR_UP, unsigned a_CTR_DOWN , unsigned a_CTR_BREAK  );


	void update(Spaceshiplocomotion &loco);
};