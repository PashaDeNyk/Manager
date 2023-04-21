#pragma once
#include "GameObject.h"
class Creature :public GameObject
{
protected:
	sf::RectangleShape rectOb;
	sf::FloatRect sprite;
	int MaxHP, HP;
	float speed, hSpeed;
	int Dps;
	float cooldown_time;
	int Direction;

	float mapPosX;
	float mapPosY;


	bool collision();
	//virtual void move();
};
