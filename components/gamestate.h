#pragma once

#include "playership.h"
#include "camera.h"
#include "Enemyship.h"
#include "bullet.h"
#include "map.h"
#include "attackarea.h"
#include "bomb.h"
#include "fallenangel.h"
#include "Ultimate.h"
class Gamestate
{
public:
	unsigned s = sfw::loadTextureMap("./components/res/wall.jpg");

	 const int enemyamount = 0;
	
	PlayerShip player;
	Camera camera;
	EnemyShip enemy[1]; 
	Bullet bullet[5];
	Map map;
	AttackArea attackarea;
	Bomb bomb;
	Fallen fallen;
	Ultimate ultimate;
	void play();
	void update(float deltaTime);
	void draw();

};