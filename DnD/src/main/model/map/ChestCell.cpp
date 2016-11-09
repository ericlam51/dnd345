#include "ChestCell.h"



ChestCell::ChestCell()
{
	type = CellHelper::CHEST_TYPE;
}


ChestCell::~ChestCell()
{
}

bool ChestCell::interactable() {
	return true;
}

bool ChestCell::walkable() {
	return true;
}