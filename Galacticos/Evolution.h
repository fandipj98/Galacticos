#pragma once
#include "wx\wx.h"

class Evolution
{
protected:
	int healthEvolve;
	int speedEvolve;
    int bonusPoints;

public:
	Evolution();

    virtual void setBonusPoints();

	int applyHealthEvolution();

	int applySpeedEvolution();

	~Evolution();
};
