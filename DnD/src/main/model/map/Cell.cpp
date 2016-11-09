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
	posY = y;
}

void Cell::setPosX(int x) {
	posX = x;
}

char Cell::getType() {
	return type;
}
