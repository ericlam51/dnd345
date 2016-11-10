#include "ChestCell.h"

IMPLEMENT_SERIAL(ChestCell, CObject, 1)

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

void ChestCell::Serialize(CArchive& archive) {
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring()) {
		archive << posX << posY << type;
	}
	else {
		archive >> posX >> posY >> type;
	}
}

void ChestCell::interact() {
	chest->interact();
}

void ChestCell::setChest(Interactable* interactable) {
	chest = interactable;
}