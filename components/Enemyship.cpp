#include "Enemyship.h"
#include <random>
#include"randomfunctions.h"
#include "gamestate.h"
EnemyShip::EnemyShip()
{
	vec2 hullvrts[] = { { 1,4 },{ 1,0 },{ -1,0 },
	{ -1,4 } };

	collider = Collider(hullvrts, 4);
	trans.m_scale = vec2{ 3,3 };

	
	renderer.offset = { 0,2 };
	renderer.dimensions = { 4,4 };

	renderer.textureHandle = sfw::loadTextureMap("./res/enemy.png");

	
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
		//collider.DebugDraw(camera, trans);
		//trans.debugDraw(camera);
		//rigidbody.debugDraw(camera, trans);
		renderer.draw(camera, trans);
	}
}
