#include "MediumMonster.h"



void MediumMonster::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\2.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	monsterptr = new wxBitmap(image);
}

MediumMonster::MediumMonster()
{
}

MediumMonster::MediumMonster(int x, int y)
{
	this->health = 150;
	this->width = 85;
	this->height = 85;
	this->positionX = x;
	this->positionY = y;
	this->speed = 2;
	this->damage = 20;
	this->killpoint = 20;
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	this->LoadBackImageBitmap();
}

MediumMonster::~MediumMonster()
{
}

void MediumMonster::move()
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

void MediumMonster::setBonusPoints()
{
	this->bonusPoints = 5;
}

void MediumMonster::evolve()
{
	this->health += applyHealthEvolution();
}