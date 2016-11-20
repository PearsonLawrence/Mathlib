#include "fallenangel.h"

Fallen::Fallen()
{
	vec2 hullvrts[] = { { 1,2 },{ 1,-2 },{ -1,-2 },
	{ -1,2 } };
	vec2 hullvrts1[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	vec2 hullvrts2[] = { { .4,.7 },{ .4,.4 },{ .3,.4 },
	{ .3,.7 } };
	vec2 hullvrts3[] = { { -.4,.7 },{ -.4,.4 },{ -.3,.4 },
	{ -.3,.7 } };
	vec2 hullvrts4[] = { { -.4,-.7 },{ -.4,-.4 },{ -.3,-.4 },
	{ -.3,-.7 } };
	vec2 hullvrts5[] = { { .4,-.7 },{ .4,-.4 },{ .3,-.4 },
	{ .3,-.7 } };
	
	sheildc[0] = Collider(hullvrts2, 4);
	sheildc[1] = Collider(hullvrts3, 4);
	sheildc[2] = Collider(hullvrts4, 4);
	sheildc[3] = Collider(hullvrts5, 4);

	sheildC = Collider(hullvrts1, 8);






	collider = Collider(hullvrts, 4);
	trans.m_scale = vec2{ 12,10 };
	sheildT.m_scale = vec2{ 7,7 };
	
	
	sheildt[0].m_parent = &sheildT;
	sheildt[1].m_parent = &sheildT;
	sheildt[2].m_parent = &sheildT;
	sheildt[3].m_parent = &sheildT;

	renderer.offset = { 0,0 };
	renderer.dimensions = { 5,5 };
	motor.m_rotationSpeed = 2;

	
		sheild[0].offset = { .35f,.45f };
		sheild[0].dimensions = { .2f,.45f };
		sheild[0].textureHandle = sfw::loadTextureMap("./res/smoke.png");
	
		sheild[1].offset = { -.35f,.45f };
		sheild[1].dimensions = { .2f,.45f };
		sheild[1].textureHandle = sfw::loadTextureMap("./res/smoke.png");

		sheild[2].offset = { .35f,-.45f };
		sheild[2].dimensions = { .2f,.45f };
		sheild[2].textureHandle = sfw::loadTextureMap("./res/smoke.png");

		sheild[3].offset = { -.35f,-.45f };
		sheild[3].dimensions = { .2f,.45f };
		sheild[3].textureHandle = sfw::loadTextureMap("./res/smoke.png");

	
	circle.offset = { 0,0 };
	circle.dimensions = { 8,8 };
	circle.textureHandle = sfw::loadTextureMap("./res/blackflame.gif");
	renderer.textureHandle = sfw::loadTextureMap("./res/fallen1.png");

}

void Fallen::update(float deltatime, Gamestate & gs)
{
	if (isAlive == true)
	{
		sheildT.m_position = trans.m_position;
		motor.update(sheildR);

			sheildr[0].integrate(sheildt[0], deltatime);
			sheildr[1].integrate(sheildt[1], deltatime);
			sheildr[2].integrate(sheildt[2], deltatime);
			sheildr[3].integrate(sheildt[3], deltatime);

		sheildR.integrate(sheildT, deltatime);
		locomotion.integrate(trans, rigidbody, deltatime);
		rigidbody.integrate(trans, deltatime);
	}

}

void Fallen::draw(const mat3 & camera)
{
	if (isAlive == true)
	{
		
		sheildC.DebugDraw(camera, sheildT);
		collider.DebugDraw(camera, trans);
		trans.debugDraw(camera);
		rigidbody.debugDraw(camera, trans);
		circle.draw(camera, sheildT);
	renderer.draw(camera, trans);
		
			sheildc[0].DebugDraw(camera, sheildt[0]);
			sheildc[1].DebugDraw(camera, sheildt[1]);
			sheildc[2].DebugDraw(camera, sheildt[2]);
			sheildc[3].DebugDraw(camera, sheildt[3]);

		
		sheild[0].draw(camera, sheildt[0]);
		sheild[1].draw(camera, sheildt[1]);
		sheild[2].draw(camera, sheildt[2]);
		sheild[3].draw(camera, sheildt[3]);
	}
}
