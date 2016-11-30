#pragma once
#include "playership.h"
#include "Enemyship.h"
#include "collider.h"
#include "collision.h"
#include "bullet.h"
#include "map.h"
#include "attackarea.h"
#include "bomb.h"
#include "fallenangel.h"
#include "Ultimate.h"
#include "chain.h"
void PlayerEnemyCollision(PlayerShip & player, EnemyShip & enemy);
void Enemycollision(EnemyShip & enemy1, EnemyShip & enemy2);
void bulletenemycollision(EnemyShip & enemy, Bullet & bullet);
void PlayerMapCollision(Map & map, PlayerShip & player);
void EnemyMapCollision(Map & map, EnemyShip & player);
void AttackAreaCollision(EnemyShip & enemy, AttackArea & attack);
void BombenemyCollision(EnemyShip & enemy, Bomb & bomb);
void PlayerFallenCollision(PlayerShip & player, Fallen & fallen);
void FallenAttackAreaCollision(Fallen & fallen, AttackArea & attack);
void bulletfallencollision(Fallen & fallen, Bullet & bullet);
void bulletsmokecollision(Fallen & fallen, Bullet & bullet);
void BombFallenCollision(Fallen & fallen, Bomb & bomb);
void bombsmokecollision(Fallen & fallen, Bomb & bomb);
void FattackingAttackAreaCollision(Fallen & fallen, AttackArea & attack);
void FallenattackPlayerCollision(Fallen & fallen, PlayerShip & player);
void EnemyorFallenUltimateCollision(Fallen & fallen, EnemyShip & enemy, Ultimate ult);
void ChainenemyCollision(EnemyShip & enemy, Chain & chain);