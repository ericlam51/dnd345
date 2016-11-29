#include "EquippedItems.h"

IMPLEMENT_SERIAL(EquippedItems, CObject, 1)

EquippedItems::EquippedItems()
{
	equipped = map<string, Item*>();
	for (int i = 0; i <= HELMET; i++) 
	{
		equipped.insert(pair<string, Item*>(ItemTypes[i], nullptr));
	}
}


EquippedItems::~EquippedItems()
{
}

void EquippedItems::equipItem(Item * item)
{
	if (item != nullptr && equipped[item->type] == nullptr)
	{
		equipped[item->type] = item;
	}
}

void EquippedItems::removeItem(string itemType)
{
	if (equipped[itemType] != nullptr)
	{
		equipped[itemType] = nullptr;
	}
}

Item * EquippedItems::getItem(string itemType)
{
	return equipped[itemType];
}

void EquippedItems::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	//now do the stuff for our specific class
	if (archive.IsStoring())
	{
		for (int i = 0; i <= HELMET; i++)
		{
			switch (i)
			{
			case 0:
				if (equipped[ItemTypes[0]] == nullptr)
				{
					armorSize = 0;
					archive << armorSize;
				}
				else
				{
					armorSize = 1;
					archive << armorSize;
					equipped[ItemTypes[0]]->Serialize(archive);
				}
				break;
			case 1:
				if (equipped[ItemTypes[1]] == nullptr)
				{
					shieldSize = 0;
					archive << shieldSize;
				}
				else
				{
					shieldSize = 1;
					archive << shieldSize;
					equipped[ItemTypes[1]]->Serialize(archive);
				}
				break;
			case 2:
				if (equipped[ItemTypes[2]] == nullptr)
				{
					weaponSize = 0;
					archive << weaponSize;
				}
				else
				{
					weaponSize = 1;
					archive << weaponSize;
					equipped[ItemTypes[2]]->Serialize(archive);
				}
				break;
			case 3:
				if (equipped[ItemTypes[3]] == nullptr)
				{
					bootsSize = 0;
					archive << bootsSize;
				}
				else
				{
					bootsSize = 1;
					archive << bootsSize;
					equipped[ItemTypes[3]]->Serialize(archive);
				}
				break;
			case 4:
				if (equipped[ItemTypes[4]] == nullptr)
				{
					ringSize = 0;
					archive << ringSize;
				}
				else
				{
					ringSize = 1;
					archive << ringSize;
					equipped[ItemTypes[4]]->Serialize(archive);
				}
				break;
			case 5:
				if (equipped[ItemTypes[5]] == nullptr)
				{
					helmetSize = 0;
					archive << helmetSize;
				}
				else
				{
					helmetSize = 1;
					archive << helmetSize;
					equipped[ItemTypes[5]]->Serialize(archive);
				}
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i <= HELMET; i++)
		{
			switch (i)
			{
			case 0:
				archive >> armorSize;
				if (armorSize == 1) 
				{
					Item* it = new Armor();
					it->Serialize(archive);

					equipped[ItemTypes[0]] = it;
				}
				break;
			case 1:
				archive >> shieldSize;
				if (shieldSize == 1)
				{
					Item* it = new Shield();
					it->Serialize(archive);

					equipped[ItemTypes[1]] = it;
				}
				break;
			case 2:
				archive >> weaponSize;
				if (weaponSize == 1)
				{
					Item* it = new Weapon();
					it->Serialize(archive);

					equipped[ItemTypes[2]] = it;
				}
				break;
			case 3:
				archive >> bootsSize;
				if (bootsSize == 1)
				{
					Item* it = new Boots();
					it->Serialize(archive);

					equipped[ItemTypes[3]] = it;
				}
				break;
			case 4:
				archive >> ringSize;
				if (ringSize == 1)
				{
					Item* it = new Ring();
					it->Serialize(archive);

					equipped[ItemTypes[4]] = it;
				}
				break;
			case 5:
				archive >> helmetSize;
				if (helmetSize == 1)
				{
					Item* it = new Helmet();
					it->Serialize(archive);

					equipped[ItemTypes[5]] == it;
				}
				break;
			}
		}
	}
}

map<string, Item*> EquippedItems::getEquipped() {
	return equipped;
}
