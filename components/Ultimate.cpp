#include "Ultimate.h"
#include "gamestate.h"
#include <iostream>
Ultimate::Ultimate()
{
	vec2 hullvrts[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	vec2 hullvrts2[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	vec2 hullvrts3[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };

	vec2 hullvrts4[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };
	vec2 hullvrts5[] = { { 2,4 },{ 4, 2 },{ 4, -2 },{ 2,-4 },{ -2,-4 },{ -4,-2 },{ -4,2 }
	,{ -2,4 } };


	collider1 = Collider(hullvrts, 8);
	collider2 = Collider(hullvrts2, 8);
	collider3 = Collider(hullvrts3, 8);
	collider4 = Collider(hullvrts3, 8);
	collider5 = Collider(hullvrts5, 8);
	trans1.m_scale = vec2{ 0,0 };
	

	trans2.m_scale = vec2{ 0,0 };
	

	trans3.m_scale = vec2{ 0,0 };
	

	
	trans4.m_scale = vec2{ 0,0 };
	

	trans5.m_scale = vec2{ 0,0 };
	

	motor.m_rotationSpeed = .5;
	motor2.m_rotationSpeed = -.5;
	motor3.m_rotationSpeed = -.5;
	renderer1.offset = { 0,0 };
	renderer1.dimensions = { 10,10 };
	renderer1.textureHandle = sfw::loadTextureMap("./res/magicc1.png");
	renderer2.offset = { 0,0 };
	renderer2.dimensions = { 10,10 };
	renderer2.textureHandle = sfw::loadTextureMap("./res/fire3.png");
	renderer3.offset = { 0,0 };
	renderer3.dimensions = { 10,10 };
	renderer3.textureHandle = sfw::loadTextureMap("./res/fireo.png");
	renderer4.offset = { 0,0 };
	renderer4.dimensions = { 10,10 };
	renderer4.textureHandle = sfw::loadTextureMap("./res/magico1.png");
	renderer5.offset = { 0,0 };
	renderer5.dimensions = { 10,10 };
	renderer5.textureHandle = sfw::loadTextureMap("./res/ult1.png");
}

void Ultimate::update(float deltatime, Gamestate & gs)
{
	trans1.m_position = gs.player.trans.m_position;
	trans2.m_position = gs.player.trans.m_position;
	trans3.m_position = gs.player.trans.m_position;
	trans4.m_position = gs.player.trans.m_position;
	
	ultcharge = gs.player.ultlvl;

	std::cout << ultcharge << "\n";

	motor.update(rigid1);
	motor2.update(rigid2);
	motor3.update(rigid4);
	pressdelay -= deltatime;
	ulttime -= deltatime;
	if (ultcharge >=10)
	{
		isactive = true;
	}
	else
	{
		isactive = false;
	}
	if (sfw::getKey('E') && charge == 1 && ultcharge >= 10 && pressdelay <= 0 && isactive == true)
	{
		ulttime = 10;
		pressdelay = 2;
		//level 1
		charge = 2;
		lvl1 = true;
	}
	if (sfw::getKey('E') && charge == 2 && ultcharge >= 11 && pressdelay <= 0 && isactive == true)
	{
		ulttime = 10;
		pressdelay = 1;
		//level 2
		charge = 3;
		lvl2 = true;
	}
	if (sfw::getKey('E') && charge == 3 && ultcharge >= 12 && pressdelay <= 0 && isactive == true)
	{
		ulttime = 20;
		pressdelay = 1;
		charge = 4;
		//level 3
		lvl3 = true;
	}

	if (lvl1 == true && ultcharge >= 10 && isactive == true && ulttime >= 0)
	{
		trans3.m_position = gs.player.trans.m_position;
		trans4.m_position = gs.player.trans.m_position;

		trans3.m_scale.x += .25;
		trans3.m_scale.y += .25;
		trans4.m_scale.x += .25;
		trans4.m_scale.y += .25;
		if (trans3.m_scale.x >= 2 &&
			trans3.m_scale.y >= 2)
		{
			trans3.m_scale.x = 2;
			trans3.m_scale.y = 2;

			rigid3.integrate(trans3, deltatime);
		}
		if (trans4.m_scale.x >= 5 &&
			trans4.m_scale.y >= 5)
		{
			trans4.m_scale.x = 5;
			trans4.m_scale.y = 5;

			rigid4.integrate(trans4, deltatime);
		}
		
	}
	if (lvl2 == true && ultcharge >= 11 && isactive == true)
	{
		trans1.m_position = gs.player.trans.m_position;

		trans1.m_scale.x += .25;
		trans1.m_scale.y += .25;
		if (trans1.m_scale.x >= 10 &&
			trans1.m_scale.y >= 10)
		{
			trans1.m_scale.x = 10;
			trans1.m_scale.y = 10;

			rigid1.integrate(trans1, deltatime);;
		}
		
	}
	if (lvl3 == true && ultcharge >= 12 && isactive == true)
	{

		trans2.m_position = gs.player.trans.m_position;

		trans2.m_scale.x += .5;
		trans2.m_scale.y += .5;
		if (trans2.m_scale.x >= 18 &&
			trans2.m_scale.y >= 18)
		{
			trans2.m_scale.x = 18;
			trans2.m_scale.y = 18;

			rigid2.integrate(trans2, deltatime);
		}
		
	}

	if (sfw::getKey('R') && charge == 2 && 
		pressdelay <= 0 && lvl1 == true && 
		activate == false && gs.player.ultlvl >= 10 && ultcharge >= 10 && isactive == true)
	{

		pressdelay = 1;
		activate = true;
		renderer5.textureHandle = sfw::loadTextureMap("./res/ult1.png");
	}
	if (activate == true && charge == 2)
	{
		trans5.m_position = gs.player.trans.m_position;


		trans5.m_scale.x++;
		trans5.m_scale.y++;
		rigid5.integrate(trans5, deltatime);

		if (trans5.m_scale.x >= 25 &&
			trans5.m_scale.y >= 25)
		{

			ulttime = 0;
		}
	}
	if (sfw::getKey('R') && charge == 3 && pressdelay <= 0 
		&& activate == false && gs.player.ultlvl >= 11 && ultcharge >= 11 && isactive == true)
	{

		pressdelay = 1;

		activate = true;
		renderer5.textureHandle = sfw::loadTextureMap("./res/roots.png");
	}
	if (activate == true && charge == 3)
	{
		trans5.m_position = gs.player.trans.m_position;

		trans5.m_scale.x++;
		trans5.m_scale.y++;
		rigid5.integrate(trans5, deltatime);

		if (trans5.m_scale.x >= 50 &&
			trans5.m_scale.y >= 50)
		{

			ulttime = 0;
		}
	}
	if (sfw::getKey('R') && charge == 4 && pressdelay <= 0 
		&& activate == false && gs.player.ultlvl >= 12 && ultcharge >= 10 && isactive == true)
	{

		pressdelay = 1;

		activate = true;
		renderer5.textureHandle = sfw::loadTextureMap("./res/fire1.png");
	}
	if (activate == true && charge == 4)
	{
		trans5.m_position = gs.player.trans.m_position;

		trans5.m_scale.x += 2;
		trans5.m_scale.y += 2;
		rigid5.integrate(trans5, deltatime);

		if (trans5.m_scale.x >= 200 &&
			trans5.m_scale.y >= 200)
		{
			
			deduct = true;

		}
		if (deduct == true)
		{
			trans5.m_scale.x -= 6;
			trans5.m_scale.y -= 6;
		
		}
		if (trans5.m_scale.x <= 0 &&
			trans5.m_scale.y <= 0 && deduct == true)
		{
			ulttime = 0;
		}
	}
	if ( isactive == true && ulttime <= 0 && lvl1 == true)
	{
			lvl1 = false;
			lvl2 = false;
			lvl3 = false;
			deduct = false;
			activate = false;
			isactive = false;
			gs.player.ultlvl = 0;
			ultcharge = 0;
			ulttime = 0;
			charge = 1;
			gs.player.ultlvl = 0;
			trans1.m_scale.x = 0;
			trans1.m_scale.y = 0;
			trans2.m_scale.x = 0;
			trans2.m_scale.y = 0;
			trans3.m_scale.x = 0;
			trans3.m_scale.y = 0;
			trans4.m_scale.x = 0;
			trans4.m_scale.y = 0;
			trans5.m_scale.x = 0;
			trans5.m_scale.y = 0;
	}
}

void Ultimate::draw(const mat3 & camera)
{
	//collider1.DebugDraw(camera, trans1);
	//collider2.DebugDraw(camera, trans2);
	//collider5.DebugDraw(camera, trans5);
	if (activate == true && isactive == true)
	{
		renderer5.draw(camera, trans5);
	}
	if (lvl1 == true && isactive == true && ultcharge >= 10)
	{
		renderer3.draw(camera, trans3);
		renderer4.draw(camera, trans4);
	}
	if (lvl2 == true && isactive == true && ultcharge >= 11)
	{
		renderer3.draw(camera, trans3);
		renderer1.draw(camera, trans1);
	}
	if (lvl3 == true && isactive == true && ultcharge >= 12)
	{
		renderer3.draw(camera, trans3);
		renderer2.draw(camera, trans2);
	}
}