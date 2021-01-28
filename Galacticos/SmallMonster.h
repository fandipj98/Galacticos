#pragma once
#include "Monster.h"

class SmallMonster : public Monster
{
private:
	void LoadBackImageBitmap();
	int xDirection;

public:
	SmallMonster();
	SmallMonster(int x, int y);

	virtual void move();
	~SmallMonster();
};

