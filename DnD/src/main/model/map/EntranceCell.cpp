#include "EntranceCell.h"

EntranceCell::EntranceCell()
{
	type = CellHelper::ENTRANCE_TYPE;
}


EntranceCell::~EntranceCell()
{
}

bool EntranceCell::interactable() {
	return true;
}

bool  EntranceCell::walkable() {
	return true;
}
