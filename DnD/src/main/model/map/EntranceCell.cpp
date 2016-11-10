#include "EntranceCell.h"

IMPLEMENT_SERIAL(EntranceCell, CObject, 1)

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

void EntranceCell::Serialize(CArchive& archive) {
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
