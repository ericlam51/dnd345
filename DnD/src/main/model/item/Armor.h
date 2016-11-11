#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(string);
	~Armor();
	Armor();
	DECLARE_SERIAL(Armor)
	void Serialize(CArchive& archive);
};

