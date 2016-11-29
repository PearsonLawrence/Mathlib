#include "Ultimate.h"
#include "gamestate.h"
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
	trans1.m_position = vec2{ 800,450 };

	trans2.m_scale = vec2{ 0,0 };
	trans2.m_position = vec2{ 800,450 };

	trans3.m_scale = vec2{ 0,0 };
	trans3.m_position = vec2{ 800,450 };

	
	trans4.m_scale = vec2{ 0,0 };
	trans4.m_position = vec2{ 800,450 };

	trans5.m_scale = vec2{ 0,0 };
	trans5.m_position = vec2{ 800,450 };

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
	motor.update(rigid1);
	motor2.update(rigid2);
	motor3.update(rigid4);
	pressdelay -= deltatime;
	if (gs.player.kills >= 0)
	{
		isactive = true;
		if (sfw::getKey('E') && charge == 0 && gs.player.kills >= 0 && pressdelay <= 0)
		{
			pressdelay = 1;
			//level 1
			charge = 1;
			lvl1 = true;
		}
		if (sfw::getKey('E') && charge == 1 && gs.player.kills >= 0 && pressdelay <= 0)
		{
			pressdelay = 1;
			//level 2
			charge = 2;
			lvl2 = true;
		}
		if (sfw::getKey('E') && charge == 2 && gs.player.kills >= 0 && pressdelay <= 0)
		{
			pressdelay = 1;
			charge = 3;
			//level 3
			lvl3 = true;
		}
		
		if(lvl1 == true)
		{ 
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
		if (lvl2 == true)
		{
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
		if (lvl3 == true)
		{
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

		if (sfw::getKey('R') && charge == 1 && pressdelay <= 0 && activate == false)
		{
			
			pressdelay = 1;
			activate = true;
			
		}
		if (activate == true)
		{
			trans5.m_scale.x++;
			trans5.m_scale.y++;
			rigid2.integrate(trans2, deltatime);

			if (trans5.m_scale.x >= 25 &&
				trans5.m_scale.y >= 25)
			{
				
				trans5.m_scale.x >= 25;
				trans5.m_scale.y >= 25;
				
				activate = false;
			}
		}


	}

}

void Ultimate::draw(const mat3 & camera)
{
	//collider1.DebugDraw(camera, trans1);
	//collider2.DebugDraw(camera, trans2);
	//collider5.DebugDraw(camera, trans5);
	if (activate == true)
	{
		renderer5.draw(camera, trans5);
	}
	if (lvl1 == true)
	{
		renderer3.draw(camera, trans3);
		renderer4.draw(camera, trans4);
		

	}
	if (lvl2 == true)
	{
		renderer3.draw(camera, trans3);
		renderer1.draw(camera, trans1);
	}
	if (lvl3 == true)
	{
		renderer3.draw(camera, trans3);
		renderer2.draw(camera, trans2);
	}
}
