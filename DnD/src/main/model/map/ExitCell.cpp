#include "ExitCell.h"
#include <iostream>

using namespace std;

IMPLEMENT_SERIAL(ExitCell, CObject, 1)

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

void ExitCell::Serialize(CArchive& archive) {
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

void ExitCell::interact() {
	cout << "You have reached the exit!";
	Sleep(1000);
	exit(1);
}