#include "shapedraw.h"



void drawcircle(const circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & b,  unsigned color)
{
	//vec2 A = { left.x, E.y };
	//vec2 B = {W.x, E.y };
	//vec2 C = { left.x, down.y };
	//vec2 D = { W.x, down.y };

	//


	//vec2 R = { b.min1().x, b.max1().y };
	//vec2 F = { b.max1().x, b.max1().y };
	//vec2 G = { b.min1().x, b.min1().y };
	//vec2 H = { b.max1().x, b.max1().y };

	///*vec3 left = L * vec3{ -1, 0, 1 };
	//vec3 right = L * vec3{ 1, 0, 1 };
	//vec3 up = L * vec3{ 0, 1 ,1 };
	//vec3 down = L * vec3{ 0,-1,1 };*/
	//
	//	sfw::drawLine(A.x, A.y, B.x, B.y, color);
	//	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	//	sfw::drawLine(A.x, A.y, C.x, C.y, color);
	//	sfw::drawLine(B.x, B.y, D.x, D.y, color);
	//

	



	sfw::drawLine(b.min1().x, b.min1().y, b.max1().x, b.min1().y, color);
	sfw::drawLine(b.min1().x, b.min1().y, b.min1().x, b.max1().y, color);
	sfw::drawLine(b.min1().x, b.max1().y, b.max1().x, b.max1().y, color);
	sfw::drawLine(b.max1().x, b.min1().y, b.max1().x, b.max1().y, color);
}
