#include "Spaceship.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

Spaceship::Spaceship()
{
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	health = 100;
	positionX = 675;
	positionY = 600;
	width = 120;
	height = 100;
	speed = 20;
	this->LoadBackImageBitmap();
}

wxBitmap Spaceship::getBitmap()
{
	return *planeptr;
}

void Spaceship::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\spaceship.png"),
		wxBITMAP_TYPE_PNG);
	image.Rescale(width, height);
	planeptr = new wxBitmap(image);
}

int Spaceship::getHealth()
{
	return this->health;
}

int Spaceship::getSpeed()
{
	return this->speed;
}


int Spaceship::getWidth()
{
	return this->width;
}

int Spaceship::getHeight()
{
	return this->height;
}

int Spaceship::getPositionX()
{
	return this->positionX;
}

int Spaceship::getPositionY()
{
	return this->positionY;
}

bool Spaceship::isHit(int x, int y, int width, int height)
{
	if (this->positionX < x + width && this->positionX + this->width > x && this->positionY < y + height && this->positionY + this->height > y) {
		return true;
	}
	else {
		return false;
	}
}

void Spaceship::collide(int damage)
{
	this->health -= damage;
}


void Spaceship::move(char key)
{
	if (key == 'W') {
		if (positionY >= 0) {
			this->positionY = this->positionY - this->speed;
		}
	}
	else if (key == 'A') {
		if (positionX >= 0) {
			this->positionX = this->positionX - this->speed;
		}
	}
	else if (key == 'S') {
		if (positionY + height <= 768) {
			this->positionY = this->positionY + this->speed;
		}
	}
	else if (key == 'D') {
		if (positionX + width <= 1366) {
			this->positionX = this->positionX + this->speed;
		}
	}
	
}

Spaceship::~Spaceship()
{
	delete planeptr;
}
