#pragma once
#include "Bullet.h"

class NormalBullet : public Bullet
{
protected:
	void LoadBackImageBitmap();
public:
	NormalBullet();
	NormalBullet(int x, int y);
	~NormalBullet();
};

