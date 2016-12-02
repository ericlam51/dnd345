#include "../header/Chest.h"
#include "../../../controller/loot/LootController.h"
#include "../../../controller/PlayModeController.h"

IMPLEMENT_SERIAL(Chest, CObject, 1)

Chest::Chest() {
	_chestContent = new ItemContainer();
}

Chest::Chest(string name, string description) : Passive(name, description){
	_chestContent = new ItemContainer();
}

Chest::~Chest() {}

void Chest::interact() {
	open();
}

void Chest::open() {
	cout << "open chest" << endl;
	Active * active = PlayModeController::instance()->getPlayer();
	LootController::instance()->startChestLoot(this, active);
	Sleep(1000);
}

void  Chest::print() {
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;
	for (int i = 1; i <= HELMET + 1; i++)
	{
		_chestContent->displayItemHelper(i);
	}
	
}

void Chest::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	CString cName(getName().c_str());
	CString cDescription(getDescription().c_str());

	if (archive.IsStoring()) {
		archive << cName << cDescription;

		_chestContent->Serialize(archive);
	}
	else {
		archive >> cName >> cDescription;

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
		_chestContent->Serialize(archive);
	}
}

void Chest::addItem(Item* item) {
	_chestContent->addItem(item);
}

ItemContainer* Chest::lootItems() {
	return _chestContent;
}
