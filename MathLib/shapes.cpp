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
	AABB retval = a;

	vec3 tp[4];
	
	tp[0] = t * vec3{ a.min1().x, a.max1().y, 1 };
	tp[1] = t * vec3{ a.max1().x, a.max1().y, 1 };
	tp[2] = t * vec3{ a.min1().x, a.min1().y ,1 };
	tp[3] = t * vec3{ a.max1().x, a.min1().y,1 };


	vec2 minv = tp[0].xy,
		 maxv = tp[0].xy;

	for (int i = 1; i < 4;  i++)
	{
		if (tp[i].x < minv.x)
		{
			minv.x = tp[i].x;
		}
		if (tp[i].x > maxv.x)
		{
			maxv.x = tp[i].x;
		}
		if (tp[i].y < minv.y)
		{
			minv.y = tp[i].y;
		}
		if (tp[i].y > maxv.y)
		{
			maxv.y = tp[i].y;
		}

		//minv = { tp[i].x < tp[i].x, tp[i].y < tp[i].y };
		//maxv = { tp[i].x > tp[i].x, tp[i].y > tp[i].y };
	}

	retval.pos = (t * vec3{ a.pos.x, a.pos.y, 1 }).xy;
	

	float halfx = (maxv.x - minv.x),
		  halfy = (maxv.y - minv.y);
		
	retval.he = { halfx, halfy };

	return retval;
}

plane operator*(const mat3 & t, const plane & p)
{
	plane retval;
	retval.pos =
		(t * vec3{ p.pos.x, p.pos.y, 1 }).xy;
	retval.dir =
		normal(t * vec3{ p.dir.x, p.dir.y, 0 }).xy;

	return retval;
}

bool operator==(const plane & a, const plane & b)
{
	return a.pos == b.pos && a.dir == b.dir;
}


vec2 AABB::min1() const
{
	return pos - he;
}

vec2 AABB::max1() const
{
	return pos + he;
}
