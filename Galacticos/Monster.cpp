#include "Monster.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Monster::Monster()
{
	this->hitGround = false;
	this->erase = false;
}

wxBitmap Monster::getBitmap()
{
	return *monsterptr;
}

void Monster::LoadBackImageBitmap()
{
}

void Monster::setHealth(int health)
{
	this->health = health;
}

int Monster::getHealth()
{
	return this->health;
}

void Monster::setSpeed(int speed)
{
	this->speed = speed;
}

int Monster::getSpeed()
{
	return this->speed;
}


int Monster::getWidth()
{
	return this->width;
}

int Monster::getHeight()
{
	return this->height;
}

int Monster::getPositionX()
{
	return positionX;
}

int Monster::getPositionY()
{
	return this->positionY;
}

void Monster::attacked(int damage)
{
	this->health -= damage;
}

bool Monster::getErase()
{
	return this->erase;
}

void Monster::move()
{

}

void Monster::evolve()
{

}

bool Monster::isHit(int x, int y, int width, int height)
{
	if (this->positionX < x + width && this->positionX + this->width > x && this->positionY < y + height && this->positionY + this->height > y) {
		return true;
	}
	else {
		return false;
	}
}

int Monster::getDamage()
{
	return this->damage;
}

int Monster::getKillpoint()
{
	return this->killpoint;
}

bool Monster::getHitground()
{
	return this->hitGround;
}


Monster::~Monster()
{
	delete monsterptr;
}