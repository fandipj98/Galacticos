#pragma once
#include "Bullet.h"

class Missile : public Bullet
{
protected:
	virtual void LoadBackImageBitmap();
public:
	Missile();
	Missile(int x, int y);
	virtual void move();
	virtual bool isHit(int x, int y, int width, int height);

	~Missile();
};

