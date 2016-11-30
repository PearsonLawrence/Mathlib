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
#include "overlay.h"
class Gamestate
{
public:

	/*unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);*/
	int d = -1;
	 const int enemyamount = 40;
	
	PlayerShip player;
	Camera camera;
	EnemyShip enemy[40]; 
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