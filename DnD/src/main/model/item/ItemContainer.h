#pragma once 

#include <map>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

class ItemContainer
{
public:
	ItemContainer();
	~ItemContainer();
	void addItem(Item*);
	void removeItem(Item*);
	Item* getItem(Item*);
	vector<Item*> getItemsOfType(string);
private:
	map<string, vector<Item*>> items;
};

