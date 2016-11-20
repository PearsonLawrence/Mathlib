#include <iostream>
#include <cstdio>
#include "bullet.h"
#include "gamestate.h"
#include <random>

Bullet::Bullet()
{
	
	vec2 hullvrts[] = { { .5, 4 },{ .5,0 },{ 1,-1 },{0,-.5},

	{-1,-1}, {-.5,0}, {-.5,4} };
		

		collider = Collider(hullvrts, 7);

		trans.m_scale = vec2{ .5,.5 };
		trans.playervelocity = { 10,10 };
		rigidbody.drag = 0.0f;
		rigidbody.angularDrag = 0.0f;
		rigidbody.mass = 0;
		renderer.offset = { 0,0 };
		renderer.dimensions = { 10,15 };

		renderer.textureHandle = sfw::loadTextureMap("./res/attack2.png");

	
}

void Bullet::update(float deltatime, Gamestate & gs)
{
	
	rigidbody.integrate(trans, deltatime);
	loco.integrate(trans, rigidbody, deltatime);
	
	
}

void Bullet::draw(const mat3 & camera)
{
	if (!isactive) return;
	//collider.DebugDraw(camera, trans);
	//rigidbody.debugDraw(camera, trans);
	renderer.draw(camera, trans);
}
