#include "gamestate.h"
#include "ObjectCollision.h"
#include "randomfunctions.h"
void Gamestate::play()
{
	if (d = -1)
	{
		d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	}
	srand(time(0));
	player.health = 100;
	player.trans.m_position = vec2{ 800, 450 };
	player.locomotion.speed = 50.f;
	player.locomotion.turnSpeed = 2.f;
	
	if (ultimate.isactive == true)
	{
		ultimate.trans1.m_position = player.trans.m_position;
		ultimate.trans2.m_position = player.trans.m_position;
		ultimate.trans3.m_position = player.trans.m_position;
		ultimate.trans4.m_position = player.trans.m_position;
		ultimate.trans5.m_position = player.trans.m_position;
	}
	ultimate.instigator = &player;
	
	if (bomb.isactive == true)
	{
		bomb.trans.m_position = player.trans.m_position;
	}
	bomb.instigator = &player;

	for (int i = 0; i < 5; ++i)
	{
		if (bullet[i].isactive == true)
		{
			bullet[i].trans.m_position = player.trans.m_position;
		}
		
		bullet[i].instigator = &player;
	}
	
	player.trans.m_facing = 0;

	for (int i = 0; i < enemyamount; i++)
	{
			enemy[i].trans.m_position = vec2{ randRange(100,1500),randRange(100,800) };
	}

	camera.scalenum = 10.0f;

	for (int i = 0; i < 4; ++i)
		chain[i].id = i;
}

void Gamestate::update(float deltaTime)
{
	if (player.health <= 0)
	{
		sfw::termContext();
	}
	if (player.killcounter >=40 && !fallen.isAlive && ultimate.activate == false)
	{
		//printf("%d", player.kills);
		fallen.isAlive = true;
		fallen.health = 20;
		fallen.trans.m_position = vec2{ 850, 470 };
		player.killcounter = 0;

	}
	if (fallen.isAlive == true )
	{
		fallen.update(deltaTime, *this);
		PlayerFallenCollision(player, fallen);
		FallenAttackAreaCollision(fallen, attackarea);
		if (fallen.attacking == true)
		{

			FattackingAttackAreaCollision(fallen, attackarea);
			FallenattackPlayerCollision(fallen, player);
		}

	}
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	ultimate.update(deltaTime, *this);
	if (bomb.isactive == true)
	{
		bomb.update(deltaTime, *this);
	}

	for (int i = 0; i < enemyamount; ++i)
	{
		enemy[i].update(deltaTime, *this);

	}

	for (int i = 0; i < 5; i++)
	{
		bullet[i].update(deltaTime, *this);
	}

	PlayerMapCollision(map, player);
	if (bomb.isactive == true)
	{
		BombFallenCollision(fallen, bomb);
		bombsmokecollision(fallen, bomb);
	}
	
	for (int i = 0; i < enemyamount; i++)
		for (int j = i + 1; j < enemyamount; j++)
			if (enemy[i].isAlive() && enemy[j].isAlive())
				Enemycollision(enemy[i], enemy[j]);

	for (int i = 0; i < enemyamount; i++)
	{
		EnemyorFallenUltimateCollision(fallen, enemy[i], ultimate);
		EnemyMapCollision(map, enemy[i]);
		PlayerEnemyCollision(player, enemy[i]);
		AttackAreaCollision(enemy[i], attackarea);
		
		if (bomb.isactive == true)
		{
			BombenemyCollision(enemy[i], bomb);
		}

		if (!enemy[i].isAlive() && ultimate.ulttime <= 0)
		{
			enemy[i].trans.m_position = vec2{ randRange(100,1500),randRange(100,800) };
			enemy[i].health = 6;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		chain[i].update(deltaTime, *this);

	}
	for (int i = 0; i < 5; i++)
	{
		if (bullet[i].isactive == true )
		{
			
			bulletfallencollision(fallen, bullet[i]);
			bulletsmokecollision(fallen, bullet[i]);
			for (int j = 0; j < enemyamount; j++)
				if (enemy[j].isAlive())
				{
					bulletenemycollision(enemy[j], bullet[i]);
					for (int k = 0; k < 4; k++)
					{
						
						ChainenemyCollision(enemy[j], chain[k]);

					}
				}
			
			
		}
	}
	
	if (sfw::getKey('M'))
	{
		camera.scalenum -= 5.f * deltaTime;
		if (camera.scalenum <= 2.0f)
		{
			camera.scalenum = 1.25;
		}
	}		
	else
	{
		camera.scalenum = 10.0f;
	}

	
}

void Gamestate::draw()
{
	
	mat3 cam = camera.getCameraMatrix();
	map.draw(cam);

	ultimate.draw(cam);
	player.draw(cam);


	if (bomb.isactive == true)
	{
		bomb.draw(cam);
	}

		for (int i = 0; i < 5; ++i)
			if (bullet[i].isactive == true)
			{
				bullet[i].draw(cam);
			
			}
		for (int i = 0; i < 4; i++)
		{
			chain[i].draw(cam);
		}
		attackarea.draw(cam);

	for (int i = 0; i < enemyamount; ++i)
		if (enemy[i].isAlive())
		{
			enemy[i].draw(cam);
			
		}


	if (fallen.isAlive == true)
	{
		fallen.draw(cam);
		
	}
	drawoverlay(d, player.health, ultimate.ultcharge, player.kills, player.killcounter);
}
