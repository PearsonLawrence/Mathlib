#include "Enemyship.h"
#include <random>
#include"randomfunctions.h"
#include "gamestate.h"
EnemyShip::EnemyShip()
{
	vec2 hullvrts[] = { { 0,.75 },{ .25, .50 },{ .25, 0 },{-.25,0},{-.25,.50} };

	collider = Collider(hullvrts, 5);

	trans.m_scale = vec2{ 8,8 };
	
}

void EnemyShip::update(float deltatime, Gamestate & gs)
{
	if (isAlive == true)
	{
		locomotion.integrate(trans, rigidbody, deltatime);
		rigidbody.integrate(trans, deltatime);
	}
	
	
}

void EnemyShip::draw(const mat3 & camera)
{
	
	if (isAlive == true)
	{
		collider.DebugDraw(camera, trans);
		trans.debugDraw(camera);
		rigidbody.debugDraw(camera, trans);
	}
}
