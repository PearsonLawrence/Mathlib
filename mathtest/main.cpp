#include <cassert>
#include <cstdio>
#include "test.h"
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include "shapes.h"
#include "collision.h"
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
	assert(((vec2{ 0,0 } *1) == vec2{ 0,0 }));
	assert(magnitude(vec2{ 0,1 }) == 1);
	assert(normal(vec2{ 0,1 }) == (vec2{ 0,1 }));

	//vec3

	assert((vec3{ 0,0,0 } == vec3{ 0,0 ,0 }));
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

	//assert(((puzzle()) == vec3{ { (2 * sqrtf(2)), (-6 - 2 * sqrtf(2)), 0 } }));
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
	circle c = { 0,0,5 };

	assert((translate(4, 0) * c == circle{ 4,0,5 }));

	assert((scale(2, 1) * c == circle{ 0,0,10 }));
	assert((scale(2, 2) * c == circle{ 0,0,10 }));
	assert((scale(1, 2) * c == circle{ 0,0,10 }));

	assert((scale(-1, 1) * c == circle{ 0,0,5 }));
	assert((rotate(45) * c == circle{ 0,0,5 }));
	AABB testA = { 1,2,3,4 };



	assert((collisionDetection1D(0, 2, 1, 3).result == true));
	assert((collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1));
	assert((collisionDetection1D(1, 3, 0, 2).penetrationDepth == 1));

	assert((collisionDetection1D(0, 2, 1, 3).collision == 1));
	assert((collisionDetection1D(1, 3, 0, 2).collision == -1));

	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);
	assert(sweptDetection1D(0, 1, -5, 3, 4, 10).result() == false);

	AABB A = { 0,0,2,4 },
		B = { 2,2,2,4 };

	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collision == vec2{ 1,0 }));
	assert((boxCollision(B, A).collision == vec2{ -1,0 }));
	AABB As = { 0,0,1,1 };
	AABB Bs = { 0,10,1,1 };

	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0,-1 }).entryTime, 4));

	CollisionDataSwept testing =
		boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 });

	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).exitTime, -4));

	AABB Bp = { 0,0,4,4 };

	plane p1{ 0,0,0,1 };
	plane p2{ 0,-10,0,1 };
	plane p3{ 0,10,0,1 };

	plane p4 = { vec2{6,6}, normal(vec2{-1,1}) };
	plane p5 = { vec2{ 6,6 }, normal(vec2{ -1,-1 }) };



	assert(planeBoxCollision(p1, Bp).result());
	assert(!planeBoxCollision(p2, Bp).result());
	assert(planeBoxCollision(p3, Bp).result());
	assert(planeBoxCollision(p4, Bp).result());
	assert(!planeBoxCollision(p5, Bp).result());

	plane p6 = { 10,0,-1,0 };

	assert(fequals(SweptplaneBoxCollision(p6, Bp, vec2{ 1,0 }).entryTime, 6.f));

	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { {-1,-1},{-1,1},{0,0} };
	hull myHull(verts, 4);
	hull otherhull(verts2, 3);
	assert((myHull.normals[0] == vec2{ 0,1 }));
	assert((myHull.normals[1] == vec2{ 1,0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));


	assert((myHull.verticies[0] == vec2{ 0,1 }));
	assert((myHull.verticies[1] == vec2{ 1,1 }));
	assert((myHull.verticies[2] == vec2{ 1,0 }));
	assert((myHull.verticies[3] == vec2{ 0,0 }));


	hull tHull = translate(1, 0) * myHull;

	assert((tHull.verticies[0] == vec2{ 1,1 }));
	assert((tHull.verticies[1] == vec2{ 2,1 }));
	assert((tHull.verticies[2] == vec2{ 2,0 }));
	assert((tHull.verticies[3] == vec2{ 1,0 }));


//	assert(fequals(HullCollision(myHull, otherhull).penetrationDepth, 0));
	assert(fequals(HullCollision(otherhull, tHull).penetrationDepth, -1));


	vec2 I = vec2{ -1,-1 };
	vec2 Ref = vec2{ 1,-1 };
	vec2 xaxis = vec2{ 1,0 };

	assert((project(I,xaxis) == -xaxis));

	vec2 ttt = reflect(-I, xaxis);
	assert((reflect(I,xaxis) == Ref));
		getchar();
		return 0;
}
