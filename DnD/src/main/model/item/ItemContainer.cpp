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
}


void ItemContainer::addItem(Item* item)
{
	if (validItem(item)) 
	{
		items[item->type].push_back(item);
	}
	else
	{
		cout << "Error: invalid item, could not add item" << endl;
	}
}

void ItemContainer::removeItem(Item* item)
{
	if (validItem(item))
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
	else
	{
		cout << "Error: invalid item, could not remove item" << endl;
	}
}

Item* ItemContainer::getItem(string type, int index)
{
	//TODO: check if valid item type
	if (validType(type)) 
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
	else
	{
		cout << "Error: invalid item type, could not get item" << endl;
		return NULL;
	}
}

vector<Item*> ItemContainer::getItemsOfType(string type)
{
	if (validType(type))
	{
		return items[type];
	}
	else
	{
		cout << "Error: invalid item type, could not get item" << endl;
		return vector<Item*>();
	}
}

bool ItemContainer::validItem(Item *item)
{
	for (int i = 0; i <= HELMET; i++) 
	{
		if (item->type == ItemTypes[i])
		{
			return true;
		}
	}
	return false;
}

bool ItemContainer::validType(string type)
{
	for (int i = 0; i <= HELMET; i++)
	{
		if (type == ItemTypes[i])
		{
			return true;
		}
	}
	return false;
}
