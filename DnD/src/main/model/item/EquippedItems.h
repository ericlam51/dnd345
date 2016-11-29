#pragma once

#include <map>
#include <string>
#include "Item.h"
#include "ItemContainer.h"

class EquippedItems : public CObject 
{
public:
	//fix implementation so can only add items that are part of item container
	EquippedItems();
	~EquippedItems();
	void equipItem(Item*);
	void removeItem(string);
	map<string, Item*> getEquipped();
	Item* getItem(string);
	DECLARE_SERIAL(EquippedItems)
	void Serialize(CArchive& archive);
private:
	map<string, Item*> equipped;
	int armorSize, shieldSize, weaponSize, bootsSize, ringSize, helmetSize;
};

