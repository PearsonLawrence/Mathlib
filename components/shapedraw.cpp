#include "shapedraw.h"



void drawcircle(const circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & b, unsigned color)
{
	sfw::drawLine(b.min1().x, b.min1().y, b.max1().x, b.min1().y, color);
	sfw::drawLine(b.min1().x, b.min1().y, b.min1().x, b.max1().y, color);
	sfw::drawLine(b.min1().x, b.max1().y, b.max1().x, b.max1().y, color);
	sfw::drawLine(b.max1().x, b.min1().y, b.max1().x, b.max1().y, color);
}
