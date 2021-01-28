#pragma once
#include "wx\wx.h"

class Bullet
{
protected:
	int damage;
	int speed;
	bool erase;
	int width;
	int height;
	wxBitmap *bulletptr = nullptr;
	virtual void LoadBackImageBitmap();
	int positionX;
	int positionY;
public:
	Bullet();
	Bullet(int x, int y);
	wxBitmap getBitmap();
	int getDamage();
	int getSpeed();
	int getWidth();
	int getHeight();
	bool getErase();
	void setErase();
	int getPositionX();
	int getPositionY();

	virtual void move();
	virtual bool isHit(int x, int y, int width, int height);

	~Bullet();
};

