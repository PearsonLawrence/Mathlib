#include "vec3.h"
#include <math.h>
#include "flops.h"

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z + rhs.z};
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float lhs, const vec3 & rhs)
{
	return vec3{ rhs.x * lhs, rhs.y * lhs, rhs.z * lhs};
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator-(const vec3 & v)
{
	return vec3{ -v.x, -v.y, -v.z };
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return fequals(lhs.x, rhs.x) && fequals(lhs.y, rhs.y) && fequals(lhs.z, rhs.z);
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return !(lhs == rhs);
}

float magnitude(const vec3 & v)
{
	return sqrt((v.x*v.x) + (v.y*v.y) + (v.z*v.z));
}

vec3 & operator*=(vec3 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

vec3 & operator/=(vec3 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}

vec3 normal(const vec3 & v)
{
	return v / magnitude(v);
}

float dot(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}
vec3 crossProduct(const vec3 & lhs, const vec3 & rhs)
{
	return  vec3{ (lhs.y*rhs.z) - (lhs.z*rhs.y),
				  (lhs.z*rhs.x) - (lhs.x*rhs.z),
				  (lhs.x*rhs.y) - (lhs.y*rhs.x)};
}
float angleBetween(const vec3 & lhs, const vec3 & rhs)
{
	return acos(dot(lhs, rhs));
}