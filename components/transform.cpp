#include "transform.h"
#include "sfwdraw.h"


//unsigned s = sfw::loadTextureMap("./res/1.png");

transform::transform() : facing(0), position({0,0}), scale({28,8})
{
	velocity1 = 5;
	velocity2 = 5;

	UpKey = 'W';
	DownKey = 'S';
	RightKey = 'A';
	LeftKey = 'D';
	SprintKey = KEY_LEFT_SHIFT;
}

transform::transform(float x, float y, int Up, int down, int left, int right, int sprint, float vely, float velx)
{

	position.x = x;
	position.y = y;
	velocity1 = vely;
	velocity2 = velx;
	scale.x = 28;
	scale.y = 8;
	facing = 0;
	UpKey = Up;
	DownKey = down;
	RightKey = right;
	LeftKey = left;
	SprintKey = sprint;
}
transform::transform(transform x, transform y, int Up, int down, int left, int right, int sprint,float vely, float velx)
{

	position.x = x.position.x;
	position.y = y.position.y;
	velocity1 = vely ;
	velocity2 = velx ;
	scale.x = 28;
	scale.y = 8;
	facing = 0;
	UpKey = Up;
	DownKey = down;
	RightKey = right;
	LeftKey = left;
	SprintKey = sprint;
}

vec2 transform::getUp()
{
	return -perp(getDirection());
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
	//sfw::drawTexture(s, position.x - 15, position.y + 15, 10, 5, 0, false, 0, WHITE);
	sfw::drawCircle(position.x, 
		                position.y, 12);

	vec2 upEnd = position - perp(getDirection()) * 20;
	sfw::drawLine(position.x, position.y,
		upEnd.x, upEnd.y, GREEN);


	vec2 dirEnd = position + getDirection()*20;
	sfw::drawLine(position.x, position.y,
		dirEnd.x, dirEnd.y, BLUE);
	
	/*position += getDirection();
	position -= getDirection();
*/

	
}

