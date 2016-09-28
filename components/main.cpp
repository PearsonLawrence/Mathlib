#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
int main()
{
	sfw::initContext();

	transform trans;

	trans.position = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 12,8 };
	while (sfw::stepContext())
	{
		trans.debugDraw();
		

		
	}

	sfw::termContext();

	getchar();

}