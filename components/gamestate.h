#pragma once

#include "playership.h"
#include "camera.h"
#include "Enemyship.h"
#include "bullet.h"
#include "map.h"
#include "attackarea.h"
#include "bomb.h"
class Gamestate
{
public:
	unsigned s = sfw::loadTextureMap("./components/res/wall.jpg");

	 const int enemyamount = 2;
	
	PlayerShip player;
	Camera camera;
	EnemyShip enemy[2]; 
	Bullet bullet[5];
	Map map;
	AttackArea attackarea;
	Bomb bomb;
	void play();
	void update(float deltaTime);
	void draw();

};