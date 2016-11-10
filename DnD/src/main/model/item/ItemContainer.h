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
	void addItem(string, Item*);
	void removeItem(string, Item*);
	Item* getItem(string, Item*);
private:
	map<string, vector<Item*>> items;
};

