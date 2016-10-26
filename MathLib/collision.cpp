#include "collision.h"
#include "vec2.h"
#include <cmath>
CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;
	float pDr = Amax - Bmin;
	float pDl = Bmax - Amin;
	float min;
	if (pDr > pDl)
	{
		min = pDl;
		retval.collision = -1;
	}
	else
	{
		min = pDr;
		retval.collision = 1;
	}
	
	

		retval.penetrationDepth = min;
	
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV = retval.penetrationDepth 
		* retval.collision;
	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	float tL, tR;
	
	tL = (Amin - Bmax) / (Bvel - Avel);
	tR = (Bmin - Amax) / (Avel - Bvel);

	retval.collision = copysignf(1, tL - tR);

	
	if (tL > tR)
	{
		retval.exitTime = tL;
		retval.entryTime = tR;
	}
	else if (tL < tR)
	{
		retval.exitTime = tR;
		retval.entryTime = tL;
	}

	
	return retval;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData1D X = collisionDetection1D(A.min1().x, A.max1().x, B.min1().x, B.max1().x);

	CollisionData1D Y = collisionDetection1D(A.min1().y, A.max1().y, B.min1().y, B.max1().y);

	CollisionData retval;

	if (X.penetrationDepth > Y.penetrationDepth)
	{
		retval.penetrationDepth = Y.penetrationDepth;
		retval.collision = vec2{ 0, Y.collision };
	}
	else
	{
		retval.penetrationDepth = X.penetrationDepth;
		retval.collision = vec2{ X.collision, 0 };
	}

	


	return retval;
}

bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}

vec2 CollisionData::MTV() const
{
		return penetrationDepth
				* collision;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}
