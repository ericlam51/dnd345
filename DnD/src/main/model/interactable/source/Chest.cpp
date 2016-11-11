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
	Sleep(1000);
}

void  Chest::print() {
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;
}

void Chest::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	CString cName(getName().c_str());
	CString cDescription(getDescription().c_str());

	if (archive.IsStoring()) {
		archive << cName << cDescription;
	}
	else {
		archive >> cName >> cDescription;

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
	}
}
