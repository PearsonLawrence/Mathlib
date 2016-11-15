#include "vec2.h"
#include <math.h>
#include <cmath>
#include "flops.h"
vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator*(float lhs, const vec2 & rhs)
{
	return vec2{ rhs.x * lhs, rhs.y * lhs };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}

vec2 operator-(const vec2 & v)
{
	return vec2{-v.x, -v.y };
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return !(lhs == rhs);
}

float magnitude(const vec2 & v)
{
	return sqrt((v.x*v.x) + (v.y*v.y));
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(vec2 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}

vec2 normal(const vec2 & v)
{
	
	return v / magnitude(v);
}

float dot(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y;
}

vec2 perp(const vec2 & v)
{
	return vec2{v.y,-v.x};
}

float angleBetween(const vec2 & lhs, const vec2 & rhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

float angle(const vec2 &v)
{
	return atan2f(v.x,v.y);
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

vec2 lerp(const vec2 start, const vec2 end, float alpha)
{
	return alpha*(end - start) + start;

		
}

vec2 quadBezier(const  vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	vec2 retval;

	vec2 mid1 = lerp(start,mid,alpha);
	vec2 mid2 = lerp(mid, end, alpha);;


	return lerp(mid1,mid2,alpha);
}

vec2 hermitSpline(const vec2 start, const vec2 s_tan, const vec2 end, const vec2 e_tan, float alpha)
{
	float tsq = alpha * alpha;
	float tcub = tsq * alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	vec2 point = h00 * start + h10 * s_tan + h01 * end + h11 * e_tan;

	return point;
}

vec2 cardinalSpline(const vec2 start, const vec2 mid, const vec2 end, float tightness, float alpha)
{
	vec2 tang0 = (mid - start) * tightness;
	vec2 tang1 = (end - mid) * tightness;

	float tsq = alpha * alpha;
	float tcub = tsq * alpha;


	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	vec2 point = h00 * start + h10 * tang0 + h01 * end + h11 * tang1;
	return point;
}

vec2 catRomSpline(const vec2 start, const vec2 mid, const vec2 end, float alpha)
{
	return cardinalSpline(start, mid, end, .5, alpha);
}

vec2 min(const vec2 & A, const vec2 & B)
{
	return vec2{ A.x < B.x ? A.x : B.x,
		A.y < B.y ? A.y : B.y };
}

vec2 max(const vec2 & A, const vec2 & B)
{
	return vec2{ A.x > B.x ? A.x : B.x,
		A.y > B.y ? A.y : B.y };
}

vec2 project(vec2 I, vec2 N)
{

	return dot(I, normal(N)) * normal(N);
}

vec2 reflect(vec2 I, vec2 N)
{
	

	return I - 2 * project(I, N);
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];

}

float &vec2::operator[](unsigned idx)
{
	return v[idx];
}
