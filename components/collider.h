#pragma once
#include "shapes.h"
#include "transform.h"
#include "collision.h"
#include <cmath>
#include "rigidbody.h"
class Collider
{

public:
	hull Hull;
	AABB box;

	Collider(const vec2 *verts, int size);
	void DebugDraw(const mat3 &T, const transform &trans);

};

	CollisionData ColliderCollision(const transform &AT, const Collider & AC,
		                            const transform &BT, const Collider &BC);

	CollisionData staticCollision(transform &AT, RigidBody &AR, const Collider & AC,
		const transform &BT, const Collider &BC);

	CollisionData dynamicCollision(transform &AT, RigidBody &AR, const Collider & AC,
		transform &BT, RigidBody &BR, const Collider &BC, float bounce);