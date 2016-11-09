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
	else 
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

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	SweptCollisionData1D X = sweptDetection1D(A.min1().x, A.max1().x, dA.x, B.min1().x, B.max1().x, dB.x);

	SweptCollisionData1D Y = sweptDetection1D(A.min1().y, A.max1().y, dA.y, B.min1().y, B.max1().y, dB.y);

	CollisionDataSwept retval;

	

	vec2 a;
	float h;
	if (X.entryTime > Y.entryTime && !isinf(X.entryTime))
	{
		a = { 1,0 };
		h = X.collision;
	
		retval.entryTime = X.entryTime;
	}
	else 
	{
		a = { 0,1 };
		h = Y.collision;
		
		retval.entryTime = Y.entryTime;
	}
	
	retval.collision = h * a;

	if (X.exitTime > Y.exitTime || isinf(X.exitTime))
	{
		retval.exitTime = Y.exitTime;
	}
	else 
	{
		retval.exitTime = X.exitTime;
	}


	return retval;
}

CollisionData planeBoxCollision(const plane & p, const AABB & b)
{
	CollisionData retval;

	vec2 BL{ b.min1().x, b.min1().y },
		 BR{ b.max1().x, b.min1().y },
		 TL{ b.min1().x, b.max1().y },
		 TR{ b.max1().x, b.max1().y };
	 
	float Pmax = dot(p.pos, p.dir);


	float FBL = dot(p.dir, BL),
		FBR = dot(p.dir, BR),
		FTL = dot(p.dir, TL),
		FTR = dot(p.dir, TR);

	float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
	float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));

	retval.penetrationDepth = Pmax - Amin;
	retval.collision = p.dir;

	return retval;
}

CollisionDataSwept SweptplaneBoxCollision(const plane & p,  const AABB & b, 
	                                      const vec2 & vel)
{
	CollisionDataSwept retval;

	vec2 BL{ b.min1().x, b.min1().y },
		BR{ b.max1().x, b.min1().y },
		TL{ b.min1().x, b.max1().y },
		TR{ b.max1().x, b.max1().y };

	float Bvel = dot(p.dir, vel);
	float Pmax = dot(p.pos, p.dir);


	float FBL = dot(p.dir, BL),
		FBR = dot(p.dir, BR),
		FTL = dot(p.dir, TL),
		FTR = dot(p.dir, TR);

	float Amin = fminf(fminf(FBL, FBR), fminf(FTL, FTR));
	float Amax = fmaxf(fmaxf(FBL, FBR), fmaxf(FTL, FTR));

	retval.entryTime = (Amin - Pmax) / (0 - Bvel);
	retval.exitTime  = (Amax - Pmax) / (0 - Bvel);


	
	return retval;
}

CollisionData HullCollision(const hull & a, const hull & b)
{
	CollisionData retval;
	retval.penetrationDepth = INFINITY;

	for(int j = 0; j < a.size; j++)
	{ 
		float AM[16];
		float AN[16];
		for (int i = 0; i < a.size; i++)
		{
			AM[i] = dot(a.verticies[i], a.normals[j]);
		}
		for (int i = 0; i < b.size; i++)
		{
			AN[i] = dot(b.verticies[i], a.normals[j]);
		}
		float aAmin = INT_MAX;
		float aAmax = INT_MIN;
		float aBmin = INT_MAX;
		float aBmax = INT_MIN;
		for (int i = 0; i < a.size; i++)
		{

			aAmin = fminf(aAmin, AM[i]);
			aAmax = fmaxf(aAmax, AM[i]);
		}

		for (int i = 0; i < a.size; i++)
		{

			aBmin = fminf(aBmin, AN[i]);
			aBmax = fmaxf(aBmax, AN[i]);
		}
		float apDr, apDl, apD;

		apDr = aAmax - aBmin;
		apDl = aBmax - aAmin;
		apD = fminf(apDr, apDl);

		float aAH = copysignf(1, apDl - apDr);

		if (apD < retval.penetrationDepth)
		{
			retval.penetrationDepth = apD;
			retval.collision = aAH * a.normals[j];
		}
		
	}

	for (int j = 0; j < b.size; j++)
	{
		
		float bM[16];
		float bN[16];
		for (int i = 0; i < b.size; i++)
		{
			bM[i] = dot(a.verticies[i], b.normals[i]);
		}
		for (int i = 0; i < b.size; i++)
		{
			bN[i] = dot(b.verticies[i], b.normals[i]);
		}
		
		float bAmin = INT_MAX;
		float bAmax = INT_MIN;
		float bBmin = INT_MAX;
		float bBmax = INT_MIN;
		for (int i = 0; i < b.size; i++)
		{

			bAmin = fminf(bAmin, bM[i]);
			bAmax = fmaxf(bAmax, bM[i]);
		}

		for (int i = 0; i < b.size; i++)
		{

			bBmin = fminf(bBmin, bN[i]);
			bBmax = fmaxf(bBmax, bN[i]);
		}
		float bpDr, bpDl, bpD;

		bpDr = bAmax - bBmin;
		bpDl = bBmax - bAmin;
		bpD = fminf(bpDr, bpDl);

		float bAH = copysignf(1, bpDl - bpDr);

		if (bpD < retval.penetrationDepth)
		{
			retval.penetrationDepth = bpD;
			retval.collision = bAH * b.normals[j];
		}

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

bool CollisionDataSwept::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}
