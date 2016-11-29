#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(string);
	~Weapon();
	Weapon();
	DECLARE_SERIAL(Weapon)
	void Serialize(CArchive& archive);
private:
	static const string enchantmentTypes[];
};

