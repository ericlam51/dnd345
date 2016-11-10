#include "../header/Chest.h"

IMPLEMENT_SERIAL(Chest, CObject, 1)

Chest::Chest() {}

Chest::Chest(string name, string description) : Passive(name, description) {

}

Chest::~Chest() {}

void Chest::interact() {
	open();
}

void Chest::open() {
	cout << "open chest" << endl;
}

void Chest::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		CString cName(getName().c_str());
		CString cDescription(getDescription().c_str());
		archive << cName << cDescription;
	}
}
