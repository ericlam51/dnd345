#include "PathCell.h"



PathCell::PathCell()
{
	type = CellHelper::PATH_TYPE;
}


PathCell::~PathCell()
{
}

char PathCell::getType() {
	return type;
}

bool PathCell::interactable() {
	return false;
}

bool PathCell::walkable() {
	return true;
}
