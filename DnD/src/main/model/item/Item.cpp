#include "Item.h"


//! constructor that initializes the item type and the name of the item if the item type is valid
//! @param itemType: the type of item to be created
//! @param name: the name of the item
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

//! getter method
//! @return the name of the item
string Item::getItemName()
{
	return itemName;
}

//! setter method
void Item::setItemName(string name)
{
	itemName = name;
}

//! check if an item has a valid type
//! @param type: type of the item
//! @return bool
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
