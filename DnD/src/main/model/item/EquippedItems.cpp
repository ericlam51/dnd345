#include "EquippedItems.h"

IMPLEMENT_SERIAL(EquippedItems, CObject, 1)

//! default constructor that initializes a map with the item types as keys with an empty value
EquippedItems::EquippedItems()
{
	for (int i = 0; i <= HELMET; i++) 
	{
		equipped.insert(pair<string, Item*>(ItemTypes[i], NULL));
	}
}


EquippedItems::~EquippedItems()
{
}

//! Add an item to the equipped items if nothing of that item type is equipped
//! @param item: item to be equipped
void EquippedItems::equipItem(Item * item)
{
	if(equipped.at(item->type) == NULL)
	{
		equipped[item->type] = item;
	}
}

//! Remove an item from the equipped items map
//! @param itemType: the type of item that will be removed
void EquippedItems::removeItem(string itemType)
{
	if (equipped.at(itemType) != NULL)
	{
		equipped[itemType] = NULL;
	}
}

//! Get an equipped item by item type
//! @param itemType: the type of item to be retrieved
//! @return an item with the specified item
Item * EquippedItems::getItem(string itemType)
{
	return equipped[itemType];
}

//! Serialize an equipped item container
void EquippedItems::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	 //now do the stuff for our specific class
	if (archive.IsStoring()) 
	{
		inventory->Serialize(archive);
	}
	else
	{
		inventory->Serialize(archive);
	}
}
