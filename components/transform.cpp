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

transform::transform(float x, float y,  float vely, float velx,float m_size,  unsigned m_COLOR)
{

	m_position.x = x;
	m_position.y = y;
	velocity1 = vely;
	velocity2 = velx;
	m_scale.x = 8;
	m_scale.y = 8;
	m_facing = 0;
	COLOR = m_COLOR;
	size = m_size;
	//UpKey = Up;
	//DownKey = down;
	//RightKey = right;
	//LeftKey = left;
	//SprintKey = sprint;
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
	return t * r * s;
	
}

mat3 transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
	{
		return getLocalTransform();
	}
	else
	{
		return m_parent->getGlobalTransform()*getLocalTransform();
	}
}

vec2 transform::getDirection()
{
	return fromAngle(m_facing);
}

vec2 transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

vec2 transform::getGlobalright() const
{
	return getGlobalTransform()[0].xy;
}

vec2 transform::getGlobalup() const
{
	return getGlobalTransform()[1].xy;
}

float transform::getGlobalAngle() const
{
	return angle(getGlobalright());
}

void transform::setDirection(const vec2 & dir)
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


void transform::debugDraw(const mat3 &t) const
{
	//sfw::drawTexture(s, m_position.x - 15, m_position.y + 15, 10, 5, 0, false, 0, WHITE);
	
	mat3 L = t * getGlobalTransform();

	vec3 pos = L[2];

	vec3 p_pos = m_parent ? t * m_parent->getGlobalTransform()[2] : pos;

	vec3 right = L * vec3{ 10, 0, 1 };
	vec3 up    = L * vec3{ 0, 10 ,1 };
	

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	sfw::drawLine(p_pos.x, p_pos.y, pos.x, pos.y, GREEN);


	sfw::drawCircle(pos.x,
		pos.y, size, 12, COLOR);



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

