#include "pickups.h"
#include "gamestate.h"
#include "randomfunctions.h"
Pickup::Pickup()
{
	vec2 hullvrts[] = { { 1,4 },{ 2, 3 },{ 2, 1 },{ 1,0 },{ -1,0 },
	{ -2,1 },{ -2,3 },{ -1,4 } };

	collider = Collider(hullvrts, 8);
	trans.m_scale = vec2{ 30,30 };

	renderer.offset = { 0,2 };
	renderer.dimensions = { 4,4 };
	rigidbody.drag = 2;
	renderer.textureHandle = sfw::loadTextureMap("./res/attack.png");

}

void Pickup::update(float deltatime, Gamestate & gs)
{
	if (gs.bomb.bombcount <= 0 && isactive == false)
	{
		isactive = true;
		trans.m_position = vec2{ randRange(100,1000),randRange(100,800) };

		rigidbody.integrate(trans, deltatime);
	}
}

void Pickup::draw(const mat3 & camera)
{
	//collider.DebugDraw(camera, trans);
	renderer.draw(camera, trans);
}
