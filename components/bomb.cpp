#include "bomb.h"

Bomb::Bomb()
{
	vec2 hullvrts[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	collider = Collider(hullvrts, 8);

	trans.m_scale = vec2{ 1,1 };
	trans.playervelocity = { 10,10 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 0;
	bombcount = 3;
	renderer.offset = { 0,0 };
	renderer.dimensions = { 10,10 };

	renderer.textureHandle = sfw::loadTextureMap("./res/explosion.png");

}

void Bomb::update(float deltatime, Gamestate & gs)
{
	if (!isactive) return;
	else
	{
		rigidbody.integrate(trans, deltatime);
		loco.integrate(trans, rigidbody, deltatime);
	}

}

void Bomb::draw(const mat3 & camera)
{
	if (!isactive) return;
	else
	{
		//collider.DebugDraw(camera, trans);
		//rigidbody.debugDraw(camera, trans);
		renderer.draw(camera, trans);
	}
	

}
