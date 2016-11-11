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
}

void EquippedItems::equipItem(Item * item)
{
	equipped->addItem(item);
	/*if(equipped.at(item->type) == NULL)
	{
		equipped[item->type] = item;
	}*/
}

void EquippedItems::removeItem(string itemType)
{
	//TODO
	/*if (equipped.at(itemType) != NULL)
	{
		equipped[itemType] = NULL;
	}*/
}

Item * EquippedItems::getItem(string itemType)
{
	//TODO: check proper item type
	return NULL;//equipped[itemType];
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