#pragma once
#include"vec2.h"
union vec3
{
	
	float v[3];
	struct
	{
		float x, y, z;
	};
	vec2 xy;
	float operator[](unsigned idx)const;
	float &operator[](unsigned idx);

};
//-----------------------------------------------------------component---------------------
vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
//-----------------------------------------------------------scalar------------------------
vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, vec3 &rhs);
vec3 operator/(const vec3 &lhs, float rhs);
//-----------------------------------------------------------unary-negation----------------
vec3 operator-(const vec3 &v);
//-----------------------------------------------------------assignment-component----------
vec3 & operator+= (vec3 &lhs, const vec3 &rhs);
vec3 & operator-=(vec3 &lhs, const vec3 &rhs);
//-----------------------------------------------------------assignment-scalar-------------
vec3 &operator*=(vec3 &lhs, float rhs);
vec3 &operator/=(vec3 &lhs, float rhs);
//-----------------------------------------------------------component-equivalence/--------
//-----------------------------------------------------------non-equivalence---------------
bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);
//-----------------------------------------------------------magnitude---------------------
float magnitude(const vec3 &v);
//-----------------------------------------------------------normal------------------------
vec3 normal(const vec3 &v);
//-----------------------------------------------------------dot-crossproduct-anglebetween-
float dot(const vec3 &lhs, const vec3 &rhs);
vec3 crossProduct(const vec3 & lhs, const vec3 & rhs);
float angleBetween(const vec3 & lhs, const vec3 & rhs);