#include "playership.h"
#include "gamestate.h"

PlayerShip::PlayerShip()
{
	vec2 hullvrts[] = { { 0,.75 },{ .25, 0 },{ -.25, 0 } };
	collider = Collider(hullvrts, 3);

	trans.m_scale = vec2{ 8,8 };

	
}

void PlayerShip::update(float deltatime, Gamestate & gs)
{
	controller.update(locomotion);
	locomotion.integrate(trans, rigidbody, deltatime);
	rigidbody.integrate(trans, deltatime);
}

void PlayerShip::draw(const mat3 &camera)
{

	collider.DebugDraw(camera, trans);
	trans.debugDraw(camera);
	rigidbody.debugDraw(camera, trans);

}
