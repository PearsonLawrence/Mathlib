#include "gamestate.h"
#include "ObjectCollision.h"
#include "randomfunctions.h"
void Gamestate::play()
{
	srand(time(0));
	player.health = 100;
	player.trans.m_position = vec2{ 800, 450 };
	player.locomotion.speed = 50.f;
	player.locomotion.turnSpeed = 2.f;
	fallen.trans.m_position = vec2{ 850, 470 };

	if (bomb.isactive == true)
	{
		bomb.trans.m_position = player.trans.m_position;
	}

	for (int i = 0; i < 5; ++i)
	{
		if (bullet[i].isactive == true)
		{
			bullet[i].trans.m_position = player.trans.m_position;
		}
		
	}
	
	player.trans.m_facing = 0;

	for (int i = 0; i < enemyamount; i++)
		if (enemy[i].isAlive == true)
		{
			enemy[i].trans.m_position = vec2{ randRange(100,1500),randRange(100,800) };
		}

	camera.scalenum = 10.0f;
}

void Gamestate::update(float deltaTime)
{/*
	if (player.health <= 0)
	{
		sfw::termContext();
	}*/
	fallen.update(deltaTime, *this);
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
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

	PlayerFallenCollision(player, fallen);
	FallenAttackAreaCollision(fallen, attackarea);
	for (int i = 0; i < enemyamount; i++)
	{
		EnemyMapCollision(map, enemy[i]);
		PlayerEnemyCollision(player, enemy[i]);
		AttackAreaCollision(enemy[i], attackarea);
		if (bomb.isactive == true)
		{
			BombenemyCollision(enemy[i], bomb);
		}
	}
	for (int i = 0; i < enemyamount; i++)
		for(int j = i + 1; j < enemyamount; j++)
			if(enemy[i].isAlive == true && enemy[j].isAlive == true)
		     Enemycollision(enemy[i], enemy[j]);

	
	for (int i = 0; i < 5; i++)
	{
		if (bullet[i].isactive == true )
		{
			for (int j = 0; j < enemyamount; j++)
				if (enemy[j].isAlive == true)
				{
					bulletenemycollision(enemy[j], bullet[i]);
				}
			
		}
	}
	
	if (sfw::getKey('M'))
	{
		camera.scalenum -= 5.f * deltaTime;
		if (camera.scalenum <= 2.0f)
		{
			camera.scalenum = .5;
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


	player.draw(cam);
	fallen.draw(cam);
	if (bomb.isactive == true)
	{
		bomb.draw(cam);
	}

		for (int i = 0; i < 5; ++i)
			if (bullet[i].isactive == true)
			{
				bullet[i].draw(cam);
			}
		
		attackarea.draw(cam);
	for (int i = 0; i < enemyamount; ++i)
		if(enemy[i].isAlive == true)
		enemy[i].draw(cam);
}
