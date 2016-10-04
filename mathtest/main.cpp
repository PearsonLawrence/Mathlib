#include <cassert>
#include <cstdio>
#include "test.h"
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
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
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 0,0 } != vec2{ 1,2 }));
	assert(((vec2{ 0,0 } -= vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } += vec2{ 0,0 }) == vec2{ 0,0 }));

	assert(((vec2{ 0,0 } -vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } +vec2{ 0,0 }) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } / 1) == vec2{ 0,0 }));
	assert(((vec2{ 0,0 } * 1) == vec2{ 0,0 }));
	assert(magnitude(vec2{ 0,1 }) == 1);
	assert(normal(vec2{ 0,1 }) == (vec2{ 0,1 }));

	//vec3

	assert((vec3{ 0,0,0 } == vec3{ 0,0 ,0}));
	assert((vec3{ 0,0,0 } != vec3{ 1,2,3 }));
	assert(((vec3{ 0,0,0 } -= vec3{ 0,0,0 }) == vec3{ 0,0,0 }));
	assert(((vec3{ 0,0,0 } += vec3{ 0,0,0 }) == vec3{ 0,0,0 }));

	assert(((vec3{ 0,0,0 } -vec3{ 0,0,0 }) == vec3{ 0,0,0 }));
	assert(((vec3{ 0,0,0 } +vec3{ 0,0,0 }) == vec3{ 0,0,0 }));
	assert(((vec3{ 0,0,0 } / 1) == vec3{ 0,0,0 }));
	assert(((vec3{ 0,0,0 } *1) == vec3{ 0,0,0 }));
	assert(magnitude(vec3{ 0,1,0 }) == 1);
	assert(normal(vec3{ 0,1,0 }) == (vec3{ 0,1,0 }));

	assert((fequals(0, 0.00001)));
	assert(fequals(magnitude(vec2{ 0,1 }), 1));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));

	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
    assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((crossProduct(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));

	assert((crossProduct(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(.23, 124, 1), 124));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	

	assert(fequals(hermitSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermitSpline(15, 40, 21, 10, 1), 21));

	float yeah = cardinalSpline(15, 40, 21, .1f, 1);
	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));


	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));








	//assert(hermitSpline(0,,1,))

	//assert(fequals(quadBezier(15, 40, 21, 0), 15));
	//assert(fequals(quadBezier(15, 40, 21, 1), 21));
		getchar();
		return 0;
}