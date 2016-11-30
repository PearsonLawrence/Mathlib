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

	/*vec2 hullvrts5[] = { {100,440}, {142,440}, {158, 486}, 
	{173, 490}, {210, 475},{245, 468}, 
	{245, 415}, {255, 400}, {370, 400},
	{400,455}, {430,455},{430, 400}, 
	{445, 382}, {580, 382}, {610,425},
	{610,475},{ 650,477 },
	{ 665, 525 },{ 665,575 },{ 625,600 },
	{ 525, 600 },{ 435, 550 },{ 365,545 },
	{ 249,620 },{ 170,620 },{ 120, 650 },
	{ 100,650 },{ 100,450 },{ 250,550 }
    };*/
	/*vec2 hullvrts6[] = { {610,425}, {610,475}, {650,477}, {665, 525},
	{665,575}, {625,600}, {525, 600}, {435, 550}, {365,545}, {249,620},
	{170,620}, {120, 650}, {100,650},{ 100,450 }, { 250,550 }
	};*/

	/*collider[4] = Collider(hullvrts5, 29);*/
	/*collider[5] = Collider(hullvrts6, 15);*/
	trans.m_scale = vec2{ 1,1 };
	trans.m_position = { 0,0 };

	renderer[0].offset = { 800,850 };
	renderer[0].dimensions = { 1500,100 };
	renderer[1].offset = { 50,450 };
	renderer[1].dimensions = { 100,900 };
	renderer[2].offset = { 1550,450 };
	renderer[2].dimensions = { 100,900 };
	renderer[3].offset = { 800,50 };
	renderer[3].dimensions = { 1500,100 };

	render.offset = { 800,450 };
	render.dimensions = { 1500,900 };

	render.textureHandle = sfw::loadTextureMap("./res/map4.png");
	

	// TODO: CLEAN UP AFTER MYSELF
	for(int i = 0; i < 4; i++)
	renderer[i].textureHandle = sfw::loadTextureMap("./res/border.png");
}

void Map::update(float deltatime, Gamestate & gs)
{
}

void Map::draw(const mat3 & camera)
{
	render.draw(camera, trans);

	
	//collider[4].DebugDraw(camera, trans);
	//collider[0].DebugDraw(camera, trans);
	//collider[1].DebugDraw(camera, trans);
	//collider[2].DebugDraw(camera, trans);
	//collider[3].DebugDraw(camera, trans);
	trans.debugDraw(camera);
	for(int i = 0; i < 4; i++)
	renderer[i].draw(camera, trans);
}
