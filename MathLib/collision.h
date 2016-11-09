#pragma once
#include "shapes.h"
struct CollisionData1D
{
	bool result; // penetrationDepth > 0
	float penetrationDepth; // how much overlap
	float collision;        // -1 or 1
	float MTV;              // penetrationDepth * collisionNormal

};

CollisionData1D collisionDetection1D(float Amin, float Amax,
	                                 float Bmin, float Bmax);
CollisionData1D collisionDetection1D(float Amin, float Amax,
	                                 float Bmin, float Bmax);

struct SweptCollisionData1D
{
	float entryTime, exitTime;
	float collision;        // -1 or 1

	bool result() const;


};

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
	                                  float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	
	float penetrationDepth; // how much overlap
	vec2 collision;        // -1 or 1
	vec2 MTV() const;              // penetrationDepth * collisionNormal
	bool result() const; // penetrationDepth > 0
};

CollisionData boxCollision(const AABB &A,
	                       const AABB &B);

struct CollisionDataSwept
{

	float entryTime, exitTime; // how much overlap
	vec2 collision;        // -1 or 1
	            // penetrationDepth * collisionNormal
	bool result() const; // penetrationDepth > 0
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
	                            const AABB &B, const vec2 &dB);

CollisionData planeBoxCollision(const plane &p, const AABB &b);
CollisionDataSwept SweptplaneBoxCollision(const plane &p, const AABB &b, const vec2 & vel);

CollisionData HullCollision(const hull &a, const hull &b);