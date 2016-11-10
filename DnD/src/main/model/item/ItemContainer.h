#pragma once 

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

class ItemContainer
{
public:
	ItemContainer();
	~ItemContainer();
	void addItem(Item*);
	void removeItem(Item*);
	Item* getItem(string, int);
	vector<Item*> getItemsOfType(string);
private:
	map<string, vector<Item*>> items;
	bool validItem(Item*);
	bool validType(string);
};

