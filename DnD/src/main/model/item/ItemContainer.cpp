#include "ItemContainer.h"


//! default constructor that initializes the item container with a map<string, vector> preset with 
//! an empty vector for each item type
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
}

//! add an item to the appropriate vector
//! @param item: the item to be added
void ItemContainer::addItem(Item* item)
{

	items[item->type].push_back(item);
}

//! remove an item to the appropriate vector
//! @param: the item to be removed
void ItemContainer::removeItem(Item* item)
{
	for (vector<Item*>::iterator it = items[item->type].begin(); it != items[item->type].end(); ++it)
	{
		if (*it == item)
		{
			items[item->type].erase(it);
			return;
		}
	}
}

//! get an item
//! @param type: the type of the item to be returned
//! @param index: the index of the item in its appropriate vector
//! @return the item requested
Item* ItemContainer::getItem(string type, int index)
{
	for (vector<Item*>::iterator it = items[type].begin(); it != items[type].end(); ++it)
	{
		//at function throws exception if nothing at index
		if (*it == items[type].at(index))
		{
			return *it;
		}
	}
	return NULL;
}

//! get the vector according to a item type
//! @param type: the type to be retrieved
//! @return the vector of items of a specific type
vector<Item*> ItemContainer::getItemsOfType(string type)
{
	return items[type];
}
