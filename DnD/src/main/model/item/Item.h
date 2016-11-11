#pragma once

#include <string>
#include <iostream>
#include <afx.h>

using namespace std;

enum ItemType { ARMOR, SHIELD, WEAPON, BOOTS, RING, HELMET };
//1:1 mapping of ItemType enum to char array since cannot convert enum to string in c++
const char* const ItemTypes[] = { "ARMOR", "SHIELD", "WEAPON", "BOOTS", "RING", "HELMET" };


class Item : public CObject
{
public:
	Item(string, string);
	Item();
	~Item();
	const string type;
	string getItemName();
	void setItemName(string);
	DECLARE_SERIAL(Item)
	void Serialize(CArchive& archive);
private:
	string itemName;
	bool validItem(string);
};

