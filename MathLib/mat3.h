#pragma once

#include "vec3.h"
// m[3] == m[1][0]
//m[0] == mm [0][0]
union mat3
{

	float m[9];     //single dimensional array
	float mm[3][3]; // multidimensional array
	vec3 c[3];      // column vectors
	vec3 operator[](unsigned idx)const;
	vec3 &operator[](unsigned idx);
};
mat3 mat3identity();
bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);
mat3 transpose(const mat3 &A);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator - (const mat3 &A);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &B);
mat3 operator*(const mat3 &A, float B);
mat3 operator*(float A, const mat3 &B);
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);
