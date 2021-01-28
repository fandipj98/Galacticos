#include "Missile.h"

Missile::Missile()
{
}

void Missile::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\bullet3.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	bulletptr = new wxBitmap(image);
}

Missile::Missile(int x, int y)
{
	width = 20;
	height = 20;
	positionX = x;
	positionY = y;
	damage = 300;
	speed = 10;
	erase = false;
	LoadBackImageBitmap();
}

Missile::~Missile()
{
}

void Missile::move()
{
	if (positionY - height >= 20) {
		this->positionY -= (10 + this->speed);
	}
	else {
		this->erase = true;
	}

}

bool Missile::isHit(int x, int y, int width, int height)
{
	if (this->positionY < y + height && this->positionY + this->height > y) {
		return true;
	}
	else {
		return false;
	}
}