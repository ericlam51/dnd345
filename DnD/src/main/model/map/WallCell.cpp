#include "WallCell.h"

WallCell::WallCell()
{
	type = CellHelper::WALL_TYPE;
}

WallCell::~WallCell()
{
}

bool WallCell::interactable() {
	return false;
}

bool WallCell::walkable() {
	return false;
}