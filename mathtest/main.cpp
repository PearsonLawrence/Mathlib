#include <cassert>
#include <cstdio>
#include "test.h"
#include <cmath>

int main()
{
	//a
	assert(test_quad(0) == -7);
	//b
	assert(Quad_eqatePlus(4, 1, -5) == 1);
	assert(Quad_eqateMinus(4, 1, -5) == -1.25);
	assert(isnan(Quad_eqatePlus(1, 0, 10)) == true);
	//c
	assert(blend(1, 10, .5) == 5.5);
	//d 
	assert(pointdist(0, 0, 0, 1) == 1.f);
	//e
	assert(inner(1, 10, 5, 2, 5, 3) == 67);
	//f

	
		getchar();
		return 0;
}