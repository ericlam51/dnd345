#include "Cell.h"

IMPLEMENT_SERIAL(Cell, CObject, 1)

Cell::Cell(){}

Cell::~Cell(){}

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

bool Cell::interactable() {
	return false;
}

bool Cell::walkable() {
	return false;
}

void Cell::interact(){}

void Cell::Serialize(CArchive& archive) {}