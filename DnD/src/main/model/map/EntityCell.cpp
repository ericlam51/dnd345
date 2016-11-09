#include "EntityCell.h"

EntityCell::EntityCell()
{
	type = CellHelper::ENTITY_TYPE;
}


EntityCell::~EntityCell()
{
}

bool EntityCell::interactable() {
	return true;
}

bool  EntityCell::walkable() {
	return true;
}