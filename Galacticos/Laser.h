#pragma once
#include "Bullet.h"

class Laser : public Bullet
{
protected:
	void LoadBackImageBitmap();
public:
	Laser();
	Laser(int x, int y);
	~Laser();
};

