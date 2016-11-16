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
		printf("%d", player.health);
		//player.trans.m_scale *= 1;
	}
}

void Enemycollision(EnemyShip & enemy1, EnemyShip & enemy2)
{
	dynamicCollision(enemy1.trans, enemy1.rigidbody, enemy1.collider
		, enemy2.trans, enemy2.rigidbody, enemy2.collider, 1);
}

void bulletenemycollision(EnemyShip & enemy, Bullet & bullet)
{       CollisionData result =
	dynamicCollision(enemy.trans, enemy.rigidbody,enemy.collider,
		bullet.trans,bullet.rigidbody, enemy.collider,1);
if (result.penetrationDepth >= 0)
{
	bullet.isactive = false;
	enemy.health -= 2;
}
}

void PlayerMapCollision(Map & map, PlayerShip & player)
{
	for(int i = 0; i < 4; i++)
		staticCollision(player.trans, player.rigidbody, player.collider
			, map.trans, map.collider[i],0);
}

void EnemyMapCollision(Map & map, EnemyShip & player)
{
	for (int i = 0; i < 4; i++)
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
