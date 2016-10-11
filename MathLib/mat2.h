#pragma once
#include "vec2.h"
// m[3] == m[1][0]
//m[0] == mm [0][0]
union mat2
{

	float m[4];     //single dimensional array
	float mm[2][2]; // multidimensional array
	vec2 c[2];      // column vectors
	vec2 operator[](unsigned idx)const;
	vec2 &operator[](unsigned idx);
};
mat2 mat2identity();
bool operator==(const mat2 &A, const mat2 &B);
bool operator!=(const mat2 &A, const mat2 &B);
mat2 transpose(const mat2 &A);
mat2 operator+(const mat2 &A, const mat2 &B);
mat2 operator-(const mat2 &A, const mat2 &B);
mat2 operator - (const mat2 &A);
mat2 operator*(const mat2 &A, const mat2 &B);
vec2 operator*(const mat2 &A, const vec2 &B);
mat2 operator*(const mat2 &A, float B);
mat2 operator*(float A, const mat2 &B );
float determinant(const mat2 &A);
mat2 inverse(const mat2 &A);

// mat2[unsigned] : subscript operator
//mat2 == mat2   :equivalence
//t4ranspose(mat2)
//mat2 + mat2    :matrix addition
//mat2 - mat2    :matrix subtraction
// -mat2         :

//mat * mat2     :matrix multiplied by matrix
//mat2 * vec2    :matrix by vector
//mat2 * float   :matrix multiplies by scalar
// float * mat2  :scalar matrix

// determination(mat2)
//inverse(mat2)