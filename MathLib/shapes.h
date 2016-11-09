#pragma once
#include "mat3.h"

struct circle { 
	vec2 pos;
	float rad; 

};
struct AABB 
{
	vec2 pos, he;
	vec2 min1() const;
	vec2 max1() const;
};

struct plane 
{
	vec2 pos, dir;
};
struct ray {};



circle operator*(const mat3 &t, const circle & c);
bool operator==(const circle &a, const circle & b);

AABB operator*(const mat3 &t, const AABB & a);
ray operator*(const mat3 &t, const ray & r);



struct hull 
{
     
	vec2 verticies[16];
	vec2 normals[16];
	unsigned int size;

	hull(const vec2 * a_vertices, unsigned a_size);
	hull();
};
hull operator*(const mat3 &t, const hull & h);
bool operator==(const hull &a, const hull &b);

plane operator*(const mat3 &t, const plane & p);
bool operator==(const plane &a, const plane & b);
