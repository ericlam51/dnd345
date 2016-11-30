#include "ItemContainer.h"

IMPLEMENT_SERIAL(ItemContainer, CObject, 1)

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
	for (int i = 0; i <= HELMET; i++)
	{
		for (vector<Item*>::iterator it = items[ItemTypes[i]].begin(); it != items[ItemTypes[i]].end(); ++it)
		{
			delete[] *it;
		}
	}
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
			it = items[item->type].erase(it);
			break;
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

int ItemContainer::size()
{
	int size = 0;
	for (int i = 0; i <= HELMET; i++)
	{
		string str(ItemTypes[i]);
		size += getItemsOfType(str).size();
	}
	return size;
}

void ItemContainer::displayItemHelper(int selection)
{
	vector<Item*> itemsSelected = getItemsOfType(ItemTypes[selection - 1]);

	if (itemsSelected.size() == 0)
	{
		cout << endl << "No items of type: " << ItemTypes[selection - 1] << endl;
	}
	else
	{
		cout << endl << "Displaying all items of type: " << ItemTypes[selection - 1] << endl;
		int i = 1;
		for (vector<Item*>::iterator it = itemsSelected.begin(); it != itemsSelected.end(); ++it)
		{
			cout << "Item: " << i++ << endl;
			cout << "Item name: " << (*it)->getItemName() << endl;
		}
	}
}

//! serialize an item container
void ItemContainer::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring())
	{
		for (int i = 0; i <= HELMET; i++) 
		{
			vector<Item*> itemsSelected = getItemsOfType(ItemTypes[i]);
			switch (i) 
			{
			case 0:
				armorSize = itemsSelected.size();
				archive << armorSize;
				break;
			case 1:
				shieldSize = itemsSelected.size();
				archive << shieldSize;
				break;
			case 2:
				weaponSize = itemsSelected.size();
				archive << weaponSize;
				break;
			case 3:
				bootsSize = itemsSelected.size();
				archive << bootsSize;
				break;
			case 4:
				ringSize = itemsSelected.size();
				archive << ringSize;
				break;
			case 5:
				helmetSize = itemsSelected.size();
				archive << helmetSize;
				break;
			}

			for (int j = 0; j < itemsSelected.size(); j++) 
			{
				itemsSelected[j]->Serialize(archive);
			}
		}
	}
	else
	{
		for (int i = 0; i <= HELMET; i++)
		{
			int size;
			switch (i)
			{
			case 0:
				archive >> armorSize;
				size = armorSize;
				break;
			case 1:
				archive >> shieldSize;
				size = shieldSize;
				break;
			case 2:
				archive >> weaponSize;
				size = weaponSize;
				break;
			case 3:
				archive >> bootsSize;
				size = bootsSize;
				break;
			case 4:
				archive >> ringSize;
				size = ringSize;
				break;
			case 5:
				archive >> helmetSize;
				size = helmetSize;
				break;
			}

			for (int j = 0; j < size; j++)
			{
				Item* item;
				switch (j)
				{
				case 0:
					item = new Armor();
					item->Serialize(archive);
					addItem(item);
					break;
				case 1:
					item = new Shield();
					item->Serialize(archive);
					addItem(item);
					break;
				case 2:
					item = new Weapon();
					item->Serialize(archive);
					addItem(item);
					break;
				case 3:
					item = new Boots();
					item->Serialize(archive);
					addItem(item);
					break;
				case 4:
					item = new Ring();
					item->Serialize(archive);
					addItem(item);
					break;
				case 5:
					item = new Helmet();
					item->Serialize(archive);
					addItem(item);
					break;
				}

					
			}
		}
	}
}