#include "sfwdraw.h"
#include <iostream>
#include "transform.h"
#include "flops.h"
int main()
{
	

	sfw::initContext(800, 600);
	
	transform trans;
	transform trans2;

	transform tranz(400,200, KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_RIGHT_SHIFT);
	
	trans.position = vec2{ 400,300 };
	trans.facing = 0;
	trans.scale = vec2{ 12,8 };
	vec2 start = { 100,100 },
		end = { 200,600 },
		mid = { 600,200 },
		e_tan = { 200, 0},
		s_tan = { 400, 200 };


	vec2 basis = { 40, 0};
	float steps = 100;
	float ang_vec = 0;
	while (sfw::stepContext())
	{
		float size = 100;
		for (int i = 0; i < size; ++i)
		{
			float t1 = i / steps;
			float t2 = (i + 1) / steps;


			vec2 v1 = catRomSpline(start, mid, end, t1);
			vec2 v2 = catRomSpline(start, mid, end, t2);

			sfw::drawLine(v1.x, v1.y, v2.x, v2.y);

		}
		
	/*	ang_vec += sfw::getDeltaTime();
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, normal(incident));

		sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);
		sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, CYAN);
		sfw::drawLine(400, 300, 400 + proj, 300, GREEN);*/
		
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