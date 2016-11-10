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
private:
	map<string, vector<Item*>> items;
};

