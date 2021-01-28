#include "SmallMonster.h"
#include <iostream>
using namespace std;

SmallMonster::SmallMonster()
{
}

SmallMonster::SmallMonster(int x, int y)
{
	this->health = 100;
	this->width = 70;
	this->height = 70;
	this->positionX = x;
	this->positionY = y;
	this->xDirection = (rand() % 2) * 2 - 1;
	this->speed = 3;
	this->damage = 10;
	this->killpoint = 10;
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->LoadBackImageBitmap();
}

SmallMonster::~SmallMonster()
{
}

void SmallMonster::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\3.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	monsterptr = new wxBitmap(image);
}

void SmallMonster::move()
{
	if (this->positionY < 780 - this->height && this->health > 0) {
		if (this->positionX + this->width >= 1366 || this->positionX <= 0) {
			this->xDirection *= -1;
		}
		this->positionX += this->xDirection * (this->speed + 2);
		this->positionY += this->speed;
	}
	else if (this->positionY >= 780 - this->height) {
		this->hitGround = true;
		this->erase = true;
	}
	else {
		this->erase = true;
	}
}
