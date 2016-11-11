#pragma once 

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

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
	DECLARE_SERIAL(ItemContainer)
	void Serialize(CArchive& archive);
private:
	map<string, vector<Item*>> items;
};

