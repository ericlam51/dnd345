#include "EntityCell.h"

IMPLEMENT_SERIAL(EntityCell, CObject, 1)

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

void EntityCell::Serialize(CArchive& archive) {
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring()) {
		archive << posX << posY << type;
	}

	/*for (int y = 0; y < height; y++) {
	for (int x = 0; x < width; x++) {
	archive << map[y][x];
	}
	}*/
	/*else
	archive >> m_name >> m_number;*/
}