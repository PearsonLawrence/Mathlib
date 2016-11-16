#include "playership.h"
#include "gamestate.h"



PlayerShip::PlayerShip()
{
	vec2 hullvrts[] = { { 0,1 },{ .25, .70 },{ .25, 0 },{ -.25,0 },{ -.25,.70 } };

	collider = Collider(hullvrts, 5);
	trans.m_scale = vec2{ 10,10 };
	
	
}

void PlayerShip::update(float deltatime, Gamestate & gs)
{
	 gs.attackarea.trans.m_position = trans.m_position;
	 gs.attackarea.trans.m_facing = trans.m_facing;
	controller.update(locomotion);
	locomotion.integrate(trans, rigidbody, deltatime);
	rigidbody.integrate(trans, deltatime);
	shootdelay -= sfw::getDeltaTime();
	float vinput = 70;
	for (int i = 0; i < gs.enemyamount; i++)
	{
		if (gs.enemy[i].health > 0)
		{
			gs.enemy[i].isAlive = true;
		}
		if (gs.enemy[i].health <= 0)
		{
			gs.enemy[i].isAlive = false;
		}
	}
	if (sfw::getMouseButton(MOUSE_BUTTON_LEFT) && shootdelay <= 0)
	{
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

				// totally valid
				//gs.bullet[i].loco.doThrust(vinput);
				
				break;
			}
			

			
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (gs.bullet[i].isactive == true)
		{
			if ((gs.bullet[i].trans.m_position.x)
				>= trans.m_position.x + 40 ||
				(gs.bullet[i].trans.m_position.x)
				<= trans.m_position.x - 40 ||
				(gs.bullet[i].trans.m_position.y)
				>= trans.m_position.y + 40 ||
				(gs.bullet[i].trans.m_position.y)
				<= trans.m_position.y - 40)
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

void PlayerShip::draw(const mat3 &camera)
{

	collider.DebugDraw(camera, trans);
	trans.debugDraw(camera);
	rigidbody.debugDraw(camera, trans);

}

