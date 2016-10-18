#include <cassert>
#include <cstdio>
#include "test.h"
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
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

	//

	//assert(fequals(hermitSpline(15, 40, 21, 10, 0), 15));
	//assert(fequals(hermitSpline(15, 40, 21, 10, 1), 21));

	//float yeah = cardinalSpline(15, 40, 21, .1f, 1);
	//assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	//assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));


	//assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	//assert(fequals(catRomSpline(15, 40, 21, 1), 21));


	//

	//assert((operator*(mat2{ 0, 1, 2, 3 }, vec2{ 1,2 }) == vec2{ 2,8 }));
	//assert(((operator*(mat2{ 0,1,2,3 }, .5)) == mat2{ 0.f, .5f, 1.f, 1.5f }));
	//assert(((operator*(.5, mat2{ 0,1,2,3 })) == mat2{ 0.f, .5f, 1.f, 1.5f }));
	//assert((determinant(mat2{ 0,2,1,3 }) == -2));
	//assert((inverse(mat2{ 0,2,1,3 }) == mat2{ -3,2,1,0 } * .5f));


	//assert((determinant(mat3{ 1,2,3,4,5,6,7,8,9 }) == 0));

	//assert((inverse(mat3{ 2,3,4,5,6,7,8,9,11 }) == mat3{ -3,-3,3,-1,10,-6,3,-6,3 } * (1.f/3)));
	//vec3 j = { 2,5,1 };

	//assert((scale(5, 1) * j == vec3{ 10,5,1 }));
	//assert((translate(0, 3) * j == vec3{2, 8, 1}));
	//assert((rotate(deg2rad(90))*j == vec3{ -5,2,1 }));
	//mat3 s = scale(2, 1);
	//mat3 t = translate(4, 3);
	//mat3 r = rotate(deg2rad(90));

	//mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };
	//bool r0 = (t*s*r == RES);

	assert(mat3identity() == mat3identity());
	assert(mat3identity() * mat3identity() == mat3identity());

	assert(((puzzle()) == vec3{ { (2 * sqrtf(2)), (-6 - 2 * sqrtf(2)), 0 } }));
	//printf("%f, %f, %f", puzzle, puzzle, puzzle);
	//
	//if ((t*s*r) == mat3{ 0, -1, 0, 2, 0, 0, 4, 3, 1 })
	//{
	//	printf("true");
	//	getchar;
	//}

	//else
	//{
	//	printf("false");
	//	getchar;
	//}



	//assert(hermitSpline(0,,1,))

	//assert(fequals(quadBezier(15, 40, 21, 0), 15));
	//assert(fequals(quadBezier(15, 40, 21, 1), 21));
	


		getchar();
		return 0;
}
