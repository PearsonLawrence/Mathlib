#include "map.h"

Map::Map()
{
	vec2 hullvrts1[] = { { 0,0 },{ 0, 900 },{ 100, 900 },
	{100,0 } };


	vec2 hullvrts2[] = { { 100,900 },{ 1500, 900 },{ 1500, 800 },
	{ 100, 800 } };

	
	vec2 hullvrts3[] = { { 1500,900 },{ 1600, 900 },{ 1600, 0},
	{ 1500,0 } };

	

	vec2 hullvrts4[] = { { 100,0 },{ 100, 100 },{ 1500, 100 },
	{ 1500,0 } };

	collider[0] = Collider(hullvrts1, 4);
	collider[1] = Collider(hullvrts2, 4);

	collider[2] = Collider(hullvrts3, 4);

	collider[3] = Collider(hullvrts4, 4);


	trans.m_scale = vec2{ 1,1 };
	trans.m_position = { 0,0 };


}

void Map::update(float deltatime, Gamestate & gs)
{
}

void Map::draw(const mat3 & camera)
{

	collider[0].DebugDraw(camera, trans);
	collider[1].DebugDraw(camera, trans);
	collider[2].DebugDraw(camera, trans);
	collider[3].DebugDraw(camera, trans);
	trans.debugDraw(camera);
}

void Map::mapDraw(const mat3 & camera)
{
	//sfw::drawTexture(s,100, 900, 800, -100);
}
