#pragma once
#include "Monster.h"
#include "Evolution.h"

class MediumMonster : public Monster, public Evolution
{
private:
	void LoadBackImageBitmap();
public:
	MediumMonster();
	MediumMonster(int x, int y);
	virtual void move();
	virtual void setBonusPoints();
	void evolve();
	~MediumMonster();
};

