#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::LoadBackImageBitmap()
{
}

wxBitmap Bullet::getBitmap()
{
	return *bulletptr;
}

Bullet::Bullet(int x, int y)
{
}


int Bullet::getDamage()
{
	return this->damage;
}

int Bullet::getSpeed()
{
	return this->speed;
}


int Bullet::getWidth()
{
	return this->width;
}

int Bullet::getHeight()
{
	return this->height;
}

int Bullet::getPositionX()
{
	return this->positionX;
}

int Bullet::getPositionY()
{
	return this->positionY;
}

void Bullet::move()
{
	if (positionY - height >= 0) {
		this->positionY -= (10 + this->speed);
	}
	else {
		this->erase = true;
	}

}

bool Bullet::getErase()
{
	return this->erase;
}

void Bullet::setErase()
{
	this->erase = true;
}

bool Bullet::isHit(int x, int y, int width, int height)
{
	if (this->positionY < y + height && this->positionY + this->height > y && this->positionX < x + width && this->positionX + this->width > x) {
		return true;
	}
	else {
		return false;
	}
}

Bullet::~Bullet()
{
}