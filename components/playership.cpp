#include "playership.h"
#include "gamestate.h"
#include "randomfunctions.h"

PlayerShip::PlayerShip()
{
	vec2 hullvrts[] = { { 1,4 },{ 2, 3 },{ 2, 1 },{ 1,0 },{ -1,0 },
	{-2,1}, {-2,3}, {-1,4} };

	collider = Collider(hullvrts, 8);
	trans.m_scale = vec2{ 2,2 };
	
	renderer.offset = { 0,2 };
	renderer.dimensions = { 4,4 };
	rigidbody.drag = 2;
	locomotion.speed = 50;
		renderer.textureHandle = sfw::loadTextureMap("./res/mage.png");
		kills = 0;
}


void PlayerShip::update(float deltatime, Gamestate & gs)
{
	 gs.attackarea.trans.m_position = trans.m_position;
	 gs.attackarea.trans.m_facing = trans.m_facing;
	controller.update(locomotion);
	locomotion.integrate(trans, rigidbody, deltatime);
	rigidbody.integrate(trans, deltatime);
	shootdelay -= sfw::getDeltaTime();
	time -= sfw::getDeltaTime();
	float vinput = 70;

	if (shootdelay <= -1)
	{
		renderer.textureHandle = sfw::loadTextureMap("./res/mage.png");

	}
	if (sfw::getKey('F') && !gs.bomb.isactive && gs.bomb.bombcount > 0 && shootdelay <= 0)
	{
		
		shootdelay = 3;
		time = 5;
		counter = 0;
		gs.bomb.bombcount--;
		gs.bomb.trans.m_facing = 0;
		gs.bomb.isactive = true;
		gs.bomb.rigidbody.reset();
		gs.bomb.trans.m_facing = trans.m_facing;
		gs.bomb.trans.m_position = trans.m_position;
		gs.bomb.rigidbody.addImpulse(trans.getUp() * 60.0f);
		
	}
	if (time <= 5)
	{
		gs.bomb.renderer.textureHandle = sfw::loadTextureMap("./res/explosion.png");

	}
	if (gs.bomb.isactive == true)
	{
		if (time <= 3 || gs.bomb.explode == true )
		{
			
			gs.bomb.explode = true;
			if (gs.bomb.explode == true )
			{

				gs.bomb.renderer.textureHandle = sfw::loadTextureMap("./res/bomb.png");

					gs.bomb.trans.m_scale.x++;
					gs.bomb.trans.m_scale.y++;
					if (gs.bomb.trans.m_scale.x >= 5 &&
						gs.bomb.trans.m_scale.y >= 5)
					{
						gs.bomb.trans.m_scale.x = 5;
						gs.bomb.trans.m_scale.y = 5;
						if (time <= 2.95)
						{
							gs.bomb.trans.m_scale.x = 1;
							gs.bomb.trans.m_scale.y = 1;
							
							gs.bomb.isactive = false;
							gs.bomb.explode = false;

							//gs.bomb.trans.m_scale = vec2{ 1,1 };*/
						}
					}
					//gs.bomb.trans.m_scale = vec2{ 1,1 };*/
			}
		}
		
	}
	

	if (sfw::getKey(' ') && shootdelay <= 0)
	{
		renderer.textureHandle = sfw::loadTextureMap("./res/mage1.png");


		shootdelay = 0.2;
 		for (int i = 0; i < maxammo; i++)
		{
			if (!gs.bullet[i].isactive)
			{
				gs.bullet[i].trans.m_facing = 0;
				gs.bullet[i].isactive = true;
				gs.bullet[i].rigidbody.reset();
			   gs.bullet[i].trans.m_facing = trans.m_facing ;
				gs.bullet[i].trans.m_position = trans.m_position;
				
				gs.bullet[i].rigidbody.addImpulse(trans.getUp() * 60.0f);
				break;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (gs.bullet[i].isactive == true)
		{
			if ((gs.bullet[i].trans.m_position.x)
				>= trans.m_position.x + 60 ||
				(gs.bullet[i].trans.m_position.x)
				<= trans.m_position.x - 60 ||
				(gs.bullet[i].trans.m_position.y)
				>= trans.m_position.y + 60 ||
				(gs.bullet[i].trans.m_position.y)
				<= trans.m_position.y - 60)
			{
				gs.bullet[i].isactive = false;
			}
		}
	}

	
	

		if (trans.m_position.x <= 0)
			trans.m_position.x = 0;
		if (trans.m_position.y <= 0)
			trans.m_position.y = 0;
		if (trans.m_position.y >= 900)
			trans.m_position.y = 900;
		if (trans.m_position.x >= 1600)
			trans.m_position.x = 1600;
	

}



void PlayerShip::draw(const mat3 & camera)
{
	
//	collider.DebugDraw(camera, trans);
//	trans.debugDraw(camera);
//	rigidbody.debugDraw(camera, trans);
	renderer.draw(camera, trans);
}
