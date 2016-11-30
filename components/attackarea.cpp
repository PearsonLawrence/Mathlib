#include "attackarea.h"
#include "gamestate.h"
AttackArea::AttackArea()
{
	vec2 hullvrts[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	collider = Collider(hullvrts, 8);
	
	trans.m_scale = vec2{ 300,300 };
}

void AttackArea::update(float deltaTime, Gamestate & gs)
{
	trans.m_position = gs.player.trans.m_position;
	trans.m_facing = gs.player.trans.m_facing;

}

void AttackArea::draw(const mat3 & camera)
{
	collider.DebugDraw(camera, trans);
}
