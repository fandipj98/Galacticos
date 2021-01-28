#include "LargeMonster.h"

void LargeMonster::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\1.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	monsterptr = new wxBitmap(image);
}

LargeMonster::LargeMonster()
{
}

LargeMonster::LargeMonster(int x, int y)
{
	this->health = 300;
	this->width = 100;
	this->height = 100;
	this->positionX = x;
	this->positionY = y;
	this->speed = 1;
	this->damage = 30;
	this->killpoint = 30;
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->LoadBackImageBitmap();
}

LargeMonster::~LargeMonster()
{
}

void LargeMonster::move()
{
	if (this->positionY < 780 - this->height && this->health > 0) {
		this->positionY += speed;
	}
	else if (this->positionY >= 780 - this->height) {
		this->hitGround = true;
		this->erase = true;
	}
	else {
		this->erase = true;
	}
}

void LargeMonster::setBonusPoints()
{
	this->bonusPoints = 10;
}

void LargeMonster::evolve()
{
	this->speed += applySpeedEvolution();
}