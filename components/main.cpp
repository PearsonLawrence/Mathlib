#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
int main()
{
	sfw::initContext();
	
	transform trans;
	transform trans2;

	transform tranz(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT);
	
	trans.position = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 12,8 };

	vec2 basis = { 40, 0};

	float ang_vec = 0;
	while (sfw::stepContext())
	{
		
		ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, normal(incident));

		sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);
		sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, CYAN);
		sfw::drawLine(400, 300, 400 + proj, 300, GREEN);
		
		/*trans2.position = trans.position - trans.getDirection() * 25.f;

		trans2.facing = trans.position.x && trans.position.y;

		trans.debugUpdate();
		trans2.debugUpdate();
		tranz.debugUpdate();
		
		trans.debugDraw();
		trans2.debugDraw();
		tranz.debugDraw();
		*/
		
	}

	sfw::termContext();

	getchar();

}