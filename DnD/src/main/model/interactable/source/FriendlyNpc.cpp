#include "../header/FriendlyNpc.h"
#include "../../Location.h"
#include <iostream>

using namespace std;


IMPLEMENT_SERIAL(FriendlyNpc, CObject, 1)

FriendlyNpc::FriendlyNpc() {}

FriendlyNpc::FriendlyNpc(string name, string description, string dialog) : Passive(name, description), dialog(dialog) {

}

FriendlyNpc::~FriendlyNpc() {}


void FriendlyNpc::print() {
	cout << "Name: " << name << endl
		<< "Description: " << description << endl
	    << "Dialog: " << dialog << endl;
}
void FriendlyNpc::interact() {
	cout << dialog << endl;
}

void FriendlyNpc::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	CString cName(getName().c_str());
	CString cDescription(getDescription().c_str());
	CString cDialog(dialog.c_str());

	if (archive.IsStoring()) {
		archive << cName << cDescription << cDialog;
	}
	else {
		archive >> cName >> cDescription >> cDialog;

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
		dialog = ((LPCTSTR)cDialog);
	}
}

