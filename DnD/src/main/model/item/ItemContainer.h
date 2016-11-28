#pragma once 

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Item.h"
#include "Armor.h"
#include "Shield.h"
#include "Weapon.h"
#include "Boots.h"
#include "Ring.h"
#include "Helmet.h"

using namespace std;

class ItemContainer : public CObject
{
public:
	ItemContainer();
	~ItemContainer();
	void addItem(Item*);
	void removeItem(Item*);
	Item* getItem(string, int);
	vector<Item*> getItemsOfType(string);
	int size();
	DECLARE_SERIAL(ItemContainer)
	void Serialize(CArchive& archive);
private:
	map<string, vector<Item*>> items;
	int armorSize, shieldSize, weaponSize, bootsSize, ringSize, helmetSize;
};

