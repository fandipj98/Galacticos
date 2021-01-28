#pragma once
#include "wx\wx.h"

class Monster
{
protected:
	int health;
	int speed;
	int width;
	int height;
	int positionX;
	int positionY;
	int damage;
	int killpoint;
	bool erase;
	bool hitGround;
	wxBitmap *monsterptr = nullptr;
	virtual void LoadBackImageBitmap();

public:
	Monster();
	wxBitmap getBitmap();

	void setHealth(int health);
	int getHealth();

	void setSpeed(int speed);
	int getSpeed();

	int getWidth();
	int getHeight();

	int getPositionX();
	int getPositionY();

	void attacked(int damage);
	bool isHit(int x, int y, int width, int height);

	bool getErase();
	
	int getDamage();
	int getKillpoint();
	bool getHitground();

	virtual void move();
	void evolve();

	~Monster();
};

