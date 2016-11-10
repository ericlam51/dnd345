#include "Item.h"



Item::Item(string itemType, string name):type(itemType)
{
	if(validItem(itemType))
	{
		itemName = name;
	}
	else
	{
		//TODO: throw exception
		cout << "Error: invalid item." << endl;
	}
}

Item::~Item()
{
}

string Item::getItemName()
{
	return itemName;
}

void Item::setItemName(string name)
{
	itemName = name;
}

bool Item::validItem(string type)
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
