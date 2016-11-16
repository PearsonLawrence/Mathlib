#pragma once

#include "playership.h"
#include "camera.h"
#include "Enemyship.h"
#include "bullet.h"
#include "map.h"
#include "attackarea.h"
class Gamestate
{
public:
	unsigned s = sfw::loadTextureMap("./components/res/wall.jpg");

	 const int enemyamount = 20;
	
	PlayerShip player;
	Camera camera;
	EnemyShip enemy[20]; 
	Bullet bullet[5];
	Map map;
	AttackArea attackarea;
	void play();
	void update(float deltaTime);
	void draw();

};