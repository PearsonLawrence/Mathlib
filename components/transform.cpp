#include "transform.h"
#include "sfwdraw.h"


//unsigned s = sfw::loadTextureMap("./res/1.png");

transform::transform() : m_facing(0), m_position({0,0}), m_scale({28,8})
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

	m_position.x = x;
	m_position.y = y;
	velocity1 = vely;
	velocity2 = velx;
	m_scale.x = 28;
	m_scale.y = 8;
	m_facing = 0;
	UpKey = Up;
	DownKey = down;
	RightKey = right;
	LeftKey = left;
	SprintKey = sprint;
}
transform::transform(transform x, transform y, int Up, int down, int left, int right, int sprint,float vely, float velx)
{

	m_position.x = x.m_position.x;
	m_position.y = y.m_position.y;
	velocity1 = vely ;
	velocity2 = velx ;
	m_scale.x = 28;
	m_scale.y = 8;
	m_facing = 0;
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

mat3 transform::getLocalTransform() const
{
	mat3 s = scale(m_scale.x, m_scale.y);
	mat3 t = translate(m_position.x, m_position.y);
	mat3 r = rotate(m_facing);
	return t * s * r;
	
}

vec2 transform::getDirection()
{
	return fromAngle(m_facing);
}

void transform::serDirection(const vec2 & dir)
{
	m_facing = ::angle(dir);
}

void transform::debugUpdate() 
{
	



	if (m_position.x < 0)
	{
		m_position.x = 800;
	}

	if (m_position.x > 800)
	{
		m_position.x = 0;
	}
	if (m_position.y < 0)
	{
		m_position.y = 600;
	}
	if (m_position.y > 600)
	{
		m_position.y = 0;
	}

}


void transform::debugDraw()
{
	//sfw::drawTexture(s, m_position.x - 15, m_position.y + 15, 10, 5, 0, false, 0, WHITE);
	sfw::drawCircle(m_position.x, 
		                m_position.y, 12, 12, RED);

	mat3 L = getLocalTransform();

	vec3 pos = vec3{ m_position.x, m_position.y, 0 };

	vec3 right = pos + L * vec3{ 7,0,0 };
	vec3 up =     pos + L * vec3{ 0,10 ,0 };
	

	sfw::drawLine(m_position.x, m_position.y, right.x, right.y, RED);
	sfw::drawLine(m_position.x, m_position.y, up.x, up.y, GREEN);




	//vec2 upEnd = m_position - perp(getDirection()) * 20;
	//sfw::drawLine(m_position.x, m_position.y,
	//	upEnd.x, upEnd.y, GREEN);


	//vec2 dirEnd = m_position + getDirection()*20;
	//sfw::drawLine(m_position.x, m_position.y,
	//	dirEnd.x, dirEnd.y, BLUE);
	//
	/*m_position += getDirection();
	m_position -= getDirection();
*/

	
}

