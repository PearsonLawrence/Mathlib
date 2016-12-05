#include "ObjectCollision.h"
#include <iostream>
void PlayerEnemyCollision(PlayerShip & player, EnemyShip & enemy)
{
	CollisionData result =
		dynamicCollision(player.trans, player.rigidbody, player.collider, enemy.trans,
			enemy.rigidbody, enemy.collider, 0);
	if (result.penetrationDepth >= 0)
	{
		player.health -= .5;
		//printf("%d", player.health);
		//player.trans.m_scale *= 1;
	}
}

void Enemycollision(EnemyShip & enemy1, EnemyShip & enemy2)
{
	dynamicCollision(enemy1.trans, enemy1.rigidbody, enemy1.collider
		, enemy2.trans, enemy2.rigidbody, enemy2.collider, 1);
}

void bulletenemycollision(EnemyShip & enemy, Bullet & bullet)
{
	if (!enemy.isAlive()) return;
	CollisionData result =
	dynamicCollision(enemy.trans, enemy.rigidbody,enemy.collider,
		bullet.trans,bullet.rigidbody, enemy.collider,1);

	if (result.result())
	{
		bullet.isactive = false;
		enemy.health -= 2;

		if (enemy.isAlive() == false)
		{
			bullet.instigator->kills++;
			bullet.instigator->killcounter++;
			bullet.instigator->ultlvl++;
		}
	}
}

void PlayerMapCollision(Map & map, PlayerShip & player)
{
	for(int i = 0; i < 6; i++)
		staticCollision(player.trans, player.rigidbody, player.collider
			, map.trans, map.collider[i],0);
}

void EnemyMapCollision(Map & map, EnemyShip & player)
{
	for (int i = 0; i < 6; i++)
		staticCollision(player.trans, player.rigidbody, player.collider
			, map.trans, map.collider[i], 0);
}

void AttackAreaCollision(EnemyShip & enemy, AttackArea & attack)
{
	CollisionData result =
	ColliderCollision(enemy.trans, enemy.collider, attack.trans, attack.collider);
	if (result.penetrationDepth >= 0)
	{
		vec2 dir = normal(attack.trans.getGlobalPosition() -
			enemy.trans.getGlobalPosition());
		enemy.rigidbody.addForce(dir * 20);

		
	}
}

void BombenemyCollision(EnemyShip & enemy, Bomb & bomb)
{
	if (!enemy.isAlive()) return;

	CollisionData result =
		dynamicCollision(enemy.trans, enemy.rigidbody, enemy.collider,
			bomb.trans, bomb.rigidbody, bomb.collider, 0);
	
	if (result.penetrationDepth >= 0 )
	{

		bomb.explode = true;
		
		if (bomb.trans.m_scale.x <= 4.99 && bomb.trans.m_scale.y <= 4.99)
			enemy.health -= 6;

		if (enemy.isAlive() == false)
		{
			bomb.instigator->kills++;
			bomb.instigator->killcounter++;
			bomb.instigator->ultlvl++;

			enemy.onDeath();
		}
	}

}

void PlayerFallenCollision(PlayerShip & player, Fallen & fallen)
{
	CollisionData result1 =
		dynamicCollision(player.trans, player.rigidbody, player.collider, fallen.trans,
			fallen.rigidbody, fallen.collider, 0);

	CollisionData result2 =
		dynamicCollision(player.trans, player.rigidbody, player.collider, fallen.sheildT,
			fallen.sheildR, fallen.sheildC, 0);


	CollisionData results[4];
	for (int i = 0; i < 4; i++)
	{
		results[i] = staticCollision(player.trans, player.rigidbody, player.collider, fallen.sheildt[i],
	   fallen.sheildc[i],1);
	}

	if (result1.penetrationDepth >= 0 || result2.penetrationDepth >= 0
		  )
	{
		player.health -= 1;
	}
}

void FallenAttackAreaCollision(Fallen & fallen, AttackArea & attack)
{
	CollisionData result =
		ColliderCollision(fallen.trans, fallen.collider, attack.trans, attack.collider);
	if (result.penetrationDepth >= 0 && fallen.isAlive == true)
	{
		vec2 dir = normal(attack.trans.getGlobalPosition() -
			fallen.trans.getGlobalPosition());
	
		    fallen.rigidbody.addForce(dir * 17);


	}
}

void bulletfallencollision(Fallen & fallen, Bullet & bullet)
{
	CollisionData result =
		ColliderCollision(fallen.trans,  fallen.collider,
			bullet.trans, fallen.collider);
	if (result.penetrationDepth >= 0)
	{
		bullet.isactive = false;
		fallen.health -= 2;
	}
}

void bulletsmokecollision(Fallen & fallen, Bullet & bullet)
{
	for (int i = 0; i < 4; i++)
	{
		CollisionData result =
			staticCollision(bullet.trans, bullet.rigidbody, bullet.collider
				, fallen.sheildt[i], fallen.sheildc[i], 1);
	}
}

void BombFallenCollision(Fallen & fallen, Bomb & bomb)
{
	CollisionData result =
		staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
			bomb.trans, bomb.collider, 0);
	if (result.penetrationDepth >= 0)
	{

		bomb.explode = true;
		if (bomb.trans.m_scale.x <= 4.99 && bomb.trans.m_scale.y <= 4.99)
			fallen.health -= 6;
	}
}

void bombsmokecollision(Fallen & fallen, Bomb & bomb)
{
	for (int i = 0; i < 4; i++)
	{
		CollisionData result =
			staticCollision(bomb.trans, bomb.rigidbody, bomb.collider
				, fallen.sheildt[i], fallen.sheildc[i], 1);
	}
}

void FattackingAttackAreaCollision(Fallen & fallen, AttackArea & attack)
{
	CollisionData result =
		ColliderCollision(fallen.attackT, fallen.attackC, attack.trans, attack.collider);
	if (result.penetrationDepth >= 0 && fallen.isAlive == true && fallen.attacking == true)
	{
		vec2 dir = normal(attack.trans.m_position - fallen.attackT.m_position);
		fallen.attackR.addForce(dir * 21);

		
	}
}

void FallenattackPlayerCollision(Fallen & fallen, PlayerShip & player)
{CollisionData result =
	staticCollision(player.trans, player.rigidbody, player.collider,
		fallen.attackT, fallen.attackC, 1);
    if (result.penetrationDepth >= 0)
    {
	player.health -= 5;
	}
}

void EnemyorFallenUltimateCollision(Fallen & fallen, EnemyShip & enemy, Ultimate ult)
{
	if (!enemy.isAlive()) return;
	if (ult.lvl1 == true)
	{
		CollisionData result1o1 =
			staticCollision(enemy.trans, enemy.rigidbody, enemy.collider,
				ult.trans1, ult.collider1, 0);
		CollisionData result2o1 =
			staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
				ult.trans1, ult.collider1, 0);
		CollisionData result1o2 =
			staticCollision(enemy.trans, enemy.rigidbody, enemy.collider,
				ult.trans2, ult.collider2, 0);
		CollisionData result2o2 =
			staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
				ult.trans2, ult.collider2, 0);
		CollisionData result1o3 =
			staticCollision(enemy.trans, enemy.rigidbody, enemy.collider,
				ult.trans4, ult.collider4, 0);
		CollisionData result2o3 =
			staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
				ult.trans4, ult.collider4, 0);
		CollisionData result3 =
			staticCollision(enemy.trans, enemy.rigidbody, enemy.collider,
				ult.trans5, ult.collider5, 0);
		CollisionData result4 =
			staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
				ult.trans5, ult.collider5, 0);

		if (result3.penetrationDepth >= 0)
		{
			enemy.health -= 15;

			if (enemy.isAlive() == false)
			{
				ult.instigator->kills++;
				enemy.onDeath();
			}
		}
		if (result4.penetrationDepth >= 0)
		{
			fallen.health -= 40;
		}
	}
}

void ChainenemyCollision(EnemyShip & enemy, Chain & chain)
{
	
	CollisionData result =
		staticCollision(enemy.trans, enemy.rigidbody, enemy.collider,
			chain.trans, chain.collider, 0);

}

void ChainFallenCollision(Fallen & fallen, Chain & chain)
{
	CollisionData result =
		staticCollision(fallen.trans, fallen.rigidbody, fallen.collider,
			chain.trans, chain.collider, 0);
}

void PlayerPickupCollision(PlayerShip & player, Pickup & pickup)
{
	CollisionData result =
		ColliderCollision(player.trans, player.collider, pickup.trans, pickup.collider);
	
	if (result.penetrationDepth >= 0 && pickup.isactive == true)
	{
		pickup.instigator->bombcount++;
		pickup.isactive = false;
	}
}
