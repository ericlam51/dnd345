#include "EquippedItems.h"

IMPLEMENT_SERIAL(EquippedItems, CObject, 1)

EquippedItems::EquippedItems()
{
	equipped = new ItemContainer();
	for (int i = 0; i <= HELMET; i++) 
	{
		//equipped.insert(pair<string, Item*>(ItemTypes[i], NULL));
	}
}


EquippedItems::~EquippedItems()
{
	delete equipped;
}

void EquippedItems::equipItem(Item * item)
{
	equipped->addItem(item);
}

void EquippedItems::removeItem(string itemType)
{
	equipped->removeItem(getItem(itemType));
}

Item * EquippedItems::getItem(string itemType)
{
	return equipped->getItem(itemType, 0);
}

void EquippedItems::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	 //now do the stuff for our specific class
	if (archive.IsStoring()) 
	{
		equipped->Serialize(archive);
	}
	else
	{
		equipped->Serialize(archive);
	}
}

ItemContainer* EquippedItems::getEquipped() {
	return equipped;
}