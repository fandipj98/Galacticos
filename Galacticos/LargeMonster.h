#pragma once
#include "Monster.h"
#include "Evolution.h"

class LargeMonster : public Monster, public Evolution
{
private:
	void LoadBackImageBitmap();
public:
	LargeMonster();
	LargeMonster(int x, int y);
	virtual void move();
	virtual void setBonusPoints();
	void evolve();
	~LargeMonster();
};

