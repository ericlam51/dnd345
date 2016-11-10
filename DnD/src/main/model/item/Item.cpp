#include "Item.h"



Item::Item(string itemType, string name):type(itemType)
{
	itemName = name;
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
