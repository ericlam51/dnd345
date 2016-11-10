#include "EquippedItems.h"



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

void EquippedItems::equipItem(Item * item)
{
	if(equipped.at(item->type) == NULL)
	{
		equipped[item->type] = item;
	}
}

void EquippedItems::removeItem(string itemType)
{
	if (equipped.at(itemType) != NULL)
	{
		equipped[itemType] = NULL;
	}
}

Item * EquippedItems::getItem(string itemType)
{
	//TODO: check proper item type
	return equipped[itemType];
}