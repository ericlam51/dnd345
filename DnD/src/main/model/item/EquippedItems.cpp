#include "EquippedItems.h"

IMPLEMENT_SERIAL(EquippedItems, CObject, 1)

EquippedItems::EquippedItems()
{
	equipped = map<string, Item*>();
	for (int i = 0; i <= HELMET; i++) 
	{
		equipped.insert(pair<string, Item*>(ItemTypes[i], nullptr));
	}
}


EquippedItems::~EquippedItems()
{
}

void EquippedItems::equipItem(Item * item)
{
	if (item != nullptr && equipped[item->type] == nullptr)
	{
		equipped[item->type] = item;
	}
}

void EquippedItems::removeItem(string itemType)
{
	if (equipped[itemType] != nullptr)
	{
		equipped[itemType] = nullptr;
	}
}

Item * EquippedItems::getItem(string itemType)
{
	return equipped[itemType];
}

void EquippedItems::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	 //now do the stuff for our specific class
	if (archive.IsStoring()) 
	{
		//equipped->Serialize(archive);
	}
	else
	{
		//equipped->Serialize(archive);
	}
}

map<string, Item*> EquippedItems::getEquipped() {
	return equipped;
}