#pragma once
#include "Item.h"
class Boots : public Item
{
public:
	Boots(string);
	~Boots();
	Boots();
	DECLARE_SERIAL(Boots)
	void Serialize(CArchive& archive);
private:
	static const string enchantmentTypes[];
};

