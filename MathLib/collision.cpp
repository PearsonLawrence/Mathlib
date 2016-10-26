#include "collision.h"
#include "vec2.h"

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
