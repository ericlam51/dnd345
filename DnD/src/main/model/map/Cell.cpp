#include "Cell.h"

Cell::Cell()
{
}


Cell::~Cell()
{
}

int Cell::getPosX() {
	return posX;
}

int Cell::getPosY() {
	return posY;
}

void Cell::setPosY(int y) {
	this->posY = y;
}

void Cell::setPosX(int x) {
	this->posX = x;
}
