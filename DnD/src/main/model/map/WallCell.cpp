#include "WallCell.h"

IMPLEMENT_SERIAL(WallCell, CObject, 1)

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

void WallCell::Serialize(CArchive& archive) {
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