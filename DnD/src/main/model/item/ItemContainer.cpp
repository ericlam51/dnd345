#include "ItemContainer.h"



ItemContainer::ItemContainer()
{
	//iterate through all item types defined in ItemType enum
	for (int i = 0; i <= HELMET; i++) 
	{
		string str(ItemTypes[i]);
		items.insert(pair<string, vector<Item*>>(str, vector<Item*>()));
	}
}


ItemContainer::~ItemContainer()
{
	//TODO: delete arraylist in map and then the map itself
}


void ItemContainer::addItem(string itemType, Item* item)
{
	//TODO: check if valid item type
	items[itemType].push_back(item);
}

void ItemContainer::removeItem(string itemType, Item* item)
{
	//TODO: check if valid item type
	for (vector<Item*>::iterator it = items[itemType].begin(); it != items[itemType].end(); ++it) 
	{
		if (*it == item) 
		{
			items[itemType].erase(it);
		}
	}
}

Item* ItemContainer::getItem(string itemType, Item* item)
{
	//TODO: check if valid item type
	for (vector<Item*>::iterator it = items[itemType].begin(); it != items[itemType].end(); ++it)
	{
		if (*it == item)
		{
			return *it;
		}
	}
	return NULL;
}
