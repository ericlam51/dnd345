#include "Item.h"

IMPLEMENT_SERIAL(Item, CObject, 1)

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

Item::Item()
{
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

void Item::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	CString cType(type.c_str());
	CString cName(getItemName().c_str());
	CString cEnchantmentType(enchantmentType.c_str());
	int cEnchantmentModifier = enchantmentModifier;

	// now do the stuff for our specific class
	if (archive.IsStoring())
	{
		archive << cType << cName << cEnchantmentType << cEnchantmentModifier;
	}
	else
	{
		archive >> cType >> cName >> cEnchantmentType >> cEnchantmentModifier;
		itemName = ((LPCTSTR)cName);
		type = ((LPCTSTR)cType);
		enchantmentType = cEnchantmentType;
		enchantmentModifier = cEnchantmentModifier;
	}
}

string Item::getEnchantmentType()
{
	return enchantmentType;
}

int Item::getEnchantmentModifier()
{
	return enchantmentModifier;
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
