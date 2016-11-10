#pragma once

#include <string>
#include <iostream>

using namespace std;

enum ItemType { ARMOR, SHIELD, WEAPON, BOOTS, RING, HELMET };
//1:1 mapping of ItemType enum to char array since cannot convert enum to string in c++
const char* const ItemTypes[] = { "ARMOR", "SHIELD", "WEAPON", "BOOTS", "RING", "HELMET" };

class Item
{
public:
	Item(string, string);
	~Item();
	const string type;
	string getItemName();
	void setItemName(string);
private:
	string itemName;
	bool validItem(string);
};

