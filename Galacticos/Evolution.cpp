#include "Evolution.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Evolution::Evolution()
{
	this->healthEvolve = 100;
	this->speedEvolve = 1;
}

void Evolution::setBonusPoints()
{
	this->bonusPoints = 1;
}

int Evolution::applyHealthEvolution()
{
	return this->healthEvolve;
}

int Evolution::applySpeedEvolution()
{
	return this->speedEvolve;
}

Evolution::~Evolution()
{
	delete evolutionptr;
}