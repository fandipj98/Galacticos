#pragma once
#include "wx\wx.h"

class Spaceship
{
private:
	int health;
	int speed;
	int width;
	int height;
	int positionX;
	int positionY;
	wxBitmap *planeptr = nullptr;
	void LoadBackImageBitmap();

public:
	Spaceship();
	wxBitmap getBitmap();
	
	int getHealth();
	int getSpeed();
	int getWidth();
	int getHeight();

	int getPositionX();
	int getPositionY();

	bool isHit(int x, int y, int width, int height);
	void collide(int damage);

	void move(char key);
	~Spaceship();
};

