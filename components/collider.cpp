#include "collider.h"
#include "shapedraw.h"
Collider::Collider(const vec2 * verts, int size) : Hull(verts,size)
{
	float minX = INFINITY;
	float maxX = -INFINITY;
	float minY = INFINITY;
	float maxY = -INFINITY;
	
	for (int i = 0; i < size; i++)
	{
		if (verts[i].x < minX)
		{
			minX = verts[i].x;
		}
		if (verts[i].x > maxX)
		{
			maxX = verts[i].x;
		}
		if (verts[i].y < minY)
		{
			minY = verts[i].y;
		}
		if (verts[i].y > maxY)
		{
			maxY = verts[i].y;
		}

	}

	vec2 max{ maxX, maxY };
	vec2 min{ minX, minY };

	box.pos = (min + max) / 2;
	box.he = (max - min) / 2;
	
}

void Collider::DebugDraw(const mat3 & T, const transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();
	drawAABB(glob * box, RED);
	drawHull(glob * Hull, GREEN);

}

CollisionData ColliderCollision(const transform & AT, const Collider & AC, const transform & BT, const Collider & BC)
{
	CollisionData retval;
	retval = boxCollision(AT.getGlobalTransform() * AC.box,
		BT.getGlobalTransform()*BC.box);

	if (retval.penetrationDepth >= 0)
	{
		retval = HullCollision(AT.getGlobalTransform()*AC.Hull,
			BT.getGlobalTransform()*BC.Hull);

	}

	return retval;
}

CollisionData staticCollision(transform & AT, RigidBody & AR, const Collider & AC,
	const transform & BT, const Collider & BC)
{


	CollisionData results = ColliderCollision(AT,
		AC, BT, BC);

	if (results.penetrationDepth >= 0)
	{

		vec2 MTV = results.penetrationDepth * results.collision;
		AT.m_position -= MTV;

		AR.velocity =
			reflect(AR.velocity, results.collision);

	}

	return results;
}

CollisionData dynamicCollision(transform & AT, RigidBody & AR, 
	const Collider & AC, transform & BT, 
	RigidBody & BR, const Collider & BC, float bnc)
{
	CollisionData results = ColliderCollision(AT,
		AC, BT, BC);
	vec2 X, Y;
	float e = bnc;

	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collision;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;


		AT.m_position -= MTV * (1-am/cm);
		BT.m_position += MTV * (1-bm/cm);


		X = ((AR.velocity * AR.mass) + (BR.velocity * BR.mass) + (-e * (AR.velocity - BR.velocity)
			* BR.mass)) / (BR.mass + AR.mass);
		Y = e*(AR.velocity - BR.velocity) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}




	return results;
}

