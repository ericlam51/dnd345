#include "PathCell.h"

IMPLEMENT_SERIAL(PathCell, CObject, 1)

PathCell::PathCell()
{
	type = CellHelper::PATH_TYPE;
}


PathCell::~PathCell()
{
}

bool PathCell::interactable() {
	return false;
}

bool PathCell::walkable() {
	return true;
}

void PathCell::Serialize(CArchive& archive) {
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

void PathCell::interact() {

}