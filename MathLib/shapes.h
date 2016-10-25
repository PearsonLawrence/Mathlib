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

struct plane {};
struct ray {};
struct hull {};


circle operator*(const mat3 &t, const circle & c);
bool operator==(const circle &a, const circle & b);

AABB operator*(const mat3 &t, const AABB & a);
ray operator*(const mat3 &t, const ray & r);
hull operator*(const mat3 &t, const hull & h);
plane operator*(const mat3 &t, const plane & p);
