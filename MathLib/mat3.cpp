#include "mat3.h"
#include "flops.h"
#include "mat2.h"
#include <cmath>
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
		fequals(A.m[4], B.m[4]) && 
		fequals(A.m[5], B.m[5]) && 
		fequals(A.m[6], B.m[6]) && 
		fequals(A.m[7], B.m[7]) &&
		fequals(A.m[8], B.m[8]);
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
	return retval;
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
	return vec3{ (A.m[0] * B.x) + (A.m[1] * B.y) + (A.m[2] * B.z),
		         (A.m[3] * B.x) + (A.m[4] * B.y) + (A.m[5] * B.z),
		         (A.m[6] * B.x) + (A.m[7] * B.y) + (A.m[8] * B.z), };
}

mat3 operator*(const mat3 & A, float B)
{
	return mat3{ A.m[0] * B,
		A.m[1] * B,
		A.m[2] * B,
		A.m[3] * B,
		A.m[4] * B, 
		A.m[5] * B, 
		A.m[6] * B, 
		A.m[7] * B, 
		A.m[8] * B, };
}

mat3 operator*(float A, const mat3 & B)
{
	return B*A;
}

float determinant(const mat3 & A)
{
	return (A.m[0] * A.m[4] * A.m[8]) + (A.m[3] * A.m[7] * A.m[2]) +
		   (A.m[6] * A.m[1] * A.m[5]) - (A.m[6] * A.m[4] * A.m[2]) -
		   (A.m[3] * A.m[1] * A.m[8]) - (A.m[0] * A.m[7] * A.m[5]);
}

mat3 inverse(const mat3 & A)
{
	mat3 G =
	{ 
		       determinant(mat2{ A.m[4],A.m[5],A.m[7],A.m[8] }),
	           determinant(mat2{ A.m[1],A.m[2],A.m[7],A.m[8] })*-1,//4
		       determinant(mat2{ A.m[1],A.m[2],A.m[4],A.m[5] }),//7

		       determinant(mat2{ A.m[3],A.m[5],A.m[6],A.m[8] })*-1,//2
		       determinant(mat2{ A.m[0],A.m[2],A.m[6],A.m[8] }),//5
		       determinant(mat2{ A.m[0],A.m[2],A.m[3],A.m[5] })*-1,//8

		       determinant(mat2{ A.m[3],A.m[4],A.m[6],A.m[7] }),//3
		       determinant(mat2{ A.m[0],A.m[1],A.m[6],A.m[7] })*-1,//6
		       determinant(mat2{ A.m[0],A.m[1],A.m[3],A.m[4] })
	};//9
		       
	
	return (1 / determinant(A))*G;
}

mat3 scale(float w, float h)
{
	return mat3{ {w,0,0,
		          0,h,0,
		          0,0,1} };
}

mat3 translate(float x, float y)
{
	return mat3{ {1,0,x,
		          0,1,y,
		          0,0,1} };
}

mat3 rotate(float a)
{
	return mat3{ {cos(a), -sin(a), 0, 
		          sin(a), cos(a), 0,  
		          0 ,0,1} };
}
