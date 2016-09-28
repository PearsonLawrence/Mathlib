#include "transform.h"
#include "sfwdraw.h"
vec2 transform::getDirection()
{
	return fromAngle(facing);
}

void transform::serDirection(const vec2 & dir)
{
	facing = ::angle(dir);
}

void transform::debugDraw()
{
	sfw::drawCircle(position.x, 
		                position.y, 12);
	vec2 upEnd = position - perp(getDirection()) * 20;
	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, RED);


	vec2 dirEnd = position + getDirection()*20;
	sfw::drawLine(position.x, position.y,
		dirEnd.x, dirEnd.y, GREEN);
	

	if (sfw::getKey('W'))
	{
		position += getDirection() * 10;
	}
	if (sfw::getKey('S'))
	{
		position -= getDirection() * 10;
	}
	if (sfw::getKey('D'))
	{
		facing -= sfw::getDeltaTime() * 5;
	}
	if (sfw::getKey('A'))
	{
		facing += sfw::getDeltaTime() * 5;
	}

}

