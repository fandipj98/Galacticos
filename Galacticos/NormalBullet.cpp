#include "NormalBullet.h"

NormalBullet::NormalBullet()
{
}


void NormalBullet::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\bullet1.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	bulletptr = new wxBitmap(image);
}

NormalBullet::NormalBullet(int x, int y)
{
	width = 20;
	height = 20;
	positionX = x;
	positionY = y;
	damage = 100;
	speed = 0;
	erase = false;
	LoadBackImageBitmap();
}


NormalBullet::~NormalBullet()
{
}
