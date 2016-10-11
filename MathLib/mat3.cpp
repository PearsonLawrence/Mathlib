#include "mat3.h"
#include "flops.h"
vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

mat3 mat3identity()
{
	return mat3{ 1,0,0,0,1,0,0,0,1 };
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return fequals(A.m[0], B.m[0]) &&
		fequals(A.m[1], B.m[1]) &&
		fequals(A.m[2], B.m[2]) &&
		fequals(A.m[3], B.m[3]) &&
		fequals(A.m[3], B.m[4]) && 
		fequals(A.m[3], B.m[5]) && 
		fequals(A.m[3], B.m[6]) && 
		fequals(A.m[3], B.m[7]) &&
		fequals(A.m[3], B.m[8]);
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return !(A == B);
}

mat3 transpose(const mat3 & A)
{
	mat3 retval = A;


	retval.m[1] = A.m[2];
	retval.m[2] = A.m[1];
	retval.m[6] = A.m[2];
	retval.m[7] = A.m[5];
	retval.m[2] = A.m[5];
	retval.m[7] = A.m[6];
	retval.m[2] = A.m[6];
	retval.m[5] = A.m[7];
	return A;
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0], A.m[1] + B.m[1],
		A.m[2] + B.m[2], A.m[3] + B.m[3], A.m[4] + B.m[4], A.m[5] + B.m[5]
		, A.m[6] + B.m[6] , A.m[7] + B.m[7], A.m[8] + B.m[8] };
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0], A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3], A.m[4] - B.m[4], A.m[5] - B.m[5]
		, A.m[6] - B.m[6] , A.m[7] - B.m[7], A.m[8] - B.m[8] };
}

mat3 operator-(const mat3 & A)
{
	return mat3{ -A.m[0], 
		-A.m[1] 
		, -A.m[2] 
		, -A.m[3]
		, -A.m[4] 
		, -A.m[5] 
		, -A.m[6] 
		, -A.m[7]
		, -A.m[8] };
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	//1,1
	//2,1
	//3,1
	//1,2
	//2,2
	//3,2
	//1,3
	//2,3
	//3,3
	return mat3{
		(A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2]),
		 (A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[2] * B.m[2]),
		 (A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2]),
		 (A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5]),
		 (A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5]),
		 (A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5]),
		 (A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8]),
		 (A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8]),
		 (A.m[2] * B.m[6]) + (A.m[5] * B.m[1]) + (A.m[5] * B.m[8]) };
		
}

vec3 operator*(const mat3 & A, const vec3 & B)
{
	return vec3();
}

mat3 operator*(const mat3 & A, float B)
{
	return mat3();
}

mat3 operator*(float A, const mat3 & B)
{
	return mat3();
}

float determinant(const mat3 & A)
{
	return 0.0f;
}

mat3 inverse(const mat3 & A)
{
	return mat3();
}
