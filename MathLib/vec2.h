#pragma once
struct vec2
{
	float x, y;
};
//-----------------------------------------------------------component--------------------
vec2 operator+(const vec2 &lhs, const vec2 &rhs);		 
vec2 operator-(const vec2 &lhs, const vec2 &rhs);	
//-----------------------------------------------------------scalar-----------------------
vec2 operator*(const vec2 &lhs, float rhs);	             
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);
//-----------------------------------------------------------unary-negation---------------
vec2 operator-(const vec2 &v);
//-----------------------------------------------------------assignment-component---------
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 & lhs, const vec2 & rhs);
//-----------------------------------------------------------assignment-scalar------------
vec2 &operator*=(vec2 &lhs, float rhs);
vec2 &operator/=(vec2 &lhs, float rhs);
//-----------------------------------------------------------component-equivalence/-------
//-----------------------------------------------------------non-equivalence--------------
bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);
//-----------------------------------------------------------magnitude--------------------
float magnitude(const vec2 &v);
//-----------------------------------------------------------normal-----------------------
vec2 normal(const vec2 &v);
//-----------------------------------------------------------dot-perpendicular-angle------
float dot(const vec2 &lhs, const vec2 &rhs);
vec2 perp(const vec2 &v);
float angleBetween(const vec2 & lhs, const vec2 & rhs);
float angle(const vec2 &v);
vec2 fromAngle(float a);
vec2 lerp(const vec2 start, const vec2 end, float alpha);

vec2 quadBezier(const vec2 start, const vec2 mid, const vec2 end, float alpha);

vec2 hermitSpline(const vec2 start, const vec2 s_tan,
	const vec2 end, const vec2 e_tan, float alpha);
vec2 cardinalSpline(const vec2 start, const vec2 mid,
	const vec2 end, float tightness, float alpha);
vec2 catRomSpline(const vec2 start, const vec2 mid, const vec2 end, float alpha);

