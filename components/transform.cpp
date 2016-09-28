#include "transform.h"
#include "sfwdraw.h"

transform::transform() : facing(0), position({0,0}), scale({28,8})
{


	UpKey = 'W';
	DownKey = 'S';
	RightKey = 'A';
	LeftKey = 'D';
	SprintKey = KEY_LEFT_SHIFT;
}

transform::transform(float x, float y, int Up, int down, int left, int right, int sprint)
{

	position.x = x;
	position.y = y;

	scale.x = 28;
	scale.y = 8;
	facing = 0;
	UpKey = Up;
	DownKey = down;
	RightKey = right;
	LeftKey = left;
	SprintKey = sprint;
}
transform::transform(transform x, transform y, int Up, int down, int left, int right, int sprint)
{

	position.x = x.position.x;
	position.y = y.position.y;

	scale.x = 28;
	scale.y = 8;
	facing = 0;
	UpKey = Up;
	DownKey = down;
	RightKey = right;
	LeftKey = left;
	SprintKey = sprint;
}

vec2 transform::getDirection()
{
	return fromAngle(facing);
}

void transform::serDirection(const vec2 & dir)
{
	facing = ::angle(dir);
}

void transform::debugUpdate()
{


	if (sfw::getKey(UpKey))
	{
		position += getDirection() * 6;


	}
	if (sfw::getKey(DownKey))
	{
		position -= getDirection() * 6;
	}
	if (sfw::getKey(LeftKey))
	{
		facing -= sfw::getDeltaTime() * 5;
	}
	if (sfw::getKey(RightKey))
	{
		facing += sfw::getDeltaTime() * 5;
	}

	if (sfw::getKey(UpKey) && sfw::getKey(SprintKey))
	{
		position += getDirection() * 10;


	}
	if (sfw::getKey(DownKey) && sfw::getKey(SprintKey))
	{
		position -= getDirection() * 10;
	}
	



	if (position.x < 0)
	{
		position.x = 800;
	}

	if (position.x > 800)
	{
		position.x = 0;
	}
	if (position.y < 0)
	{
		position.y = 600;
	}
	if (position.y > 600)
	{
		position.y = 0;
	}

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
	
	position += getDirection();
	position -= getDirection();


	
}

