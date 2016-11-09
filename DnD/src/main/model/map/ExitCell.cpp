#include "ExitCell.h"

ExitCell::ExitCell()
{
	type = CellHelper::EXIT_TYPE;
}


ExitCell::~ExitCell()
{
}

bool ExitCell::interactable() {
	return true;
}

bool  ExitCell::walkable() {
	return true;
}
