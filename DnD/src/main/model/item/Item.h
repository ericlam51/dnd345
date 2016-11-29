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
	string getItemName();
	void setItemName(string);
	DECLARE_SERIAL(Item)
	void Serialize(CArchive& archive);
	string type;
	string getEnchantmentType();
	int getEnchantmentModifier();
private:
	string itemName;
	bool validItem(string);
protected:
	string enchantmentType;
	int enchantmentModifier;
};

