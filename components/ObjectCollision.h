#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "collider.h"
#include "collision.h"
#include "bullet.h"
#include "map.h"
#include "attackarea.h"
#include "bomb.h"
void PlayerEnemyCollision(PlayerShip & player, EnemyShip & enemy);
void Enemycollision(EnemyShip & enemy1, EnemyShip & enemy2);
void bulletenemycollision(EnemyShip & enemy, Bullet & bullet);
void PlayerMapCollision(Map & map, PlayerShip & player);
void EnemyMapCollision(Map & map, EnemyShip & player);
void AttackAreaCollision(EnemyShip & enemy, AttackArea & attack);
void BombenemyCollision(EnemyShip & enemy, Bomb & bomb);