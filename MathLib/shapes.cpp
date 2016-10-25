#include "shapes.h"
#include "vec2.h"
#include "mat3.h"
#include "flops.h"
circle operator*(const mat3 & t, const circle & c)
{

	circle retval;

	retval.pos = (t*vec3{ c.pos.x, c.pos.y, 1 }).xy;


     retval.rad = c.rad;
	float xRad = magnitude(t * vec3{ retval.rad,0,0 });
	float yRad = magnitude(t * vec3{ 0,retval.rad,0 });


	retval.rad = xRad > yRad ? xRad : yRad;

	 return retval;



}

bool operator==(const circle & a, const circle & b)
{
	return a.pos == b.pos && fequals(a.rad, b.rad);
}

AABB operator*(const mat3 & t, const AABB & a)
{
	AABB retval;

	retval.pos = (t*vec3{ a.pos.x, a.pos.y, 1 }).xy;


	retval.he = a.he;
	float xhe = magnitude(t * vec3{ retval.he.x,0,0 });
	float yhe = magnitude(t * vec3{ 0,retval.he.y,0 });


	retval.he = {xhe, yhe};

	return retval;
}


vec2 AABB::min1() const
{
	return pos - he;
}

vec2 AABB::max1() const
{
	return pos + he;
}
