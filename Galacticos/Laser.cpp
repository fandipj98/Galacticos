#include "Laser.h"

Laser::Laser()
{
}

void Laser::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\bullet2.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	bulletptr = new wxBitmap(image);
}

Laser::Laser(int x, int y)
{
	width = 20;
	height = 20;
	positionX = x;
	positionY = y;
	damage = 150;
	speed = 5;
	erase = false;
	LoadBackImageBitmap();
}

Laser::~Laser()
{
}
