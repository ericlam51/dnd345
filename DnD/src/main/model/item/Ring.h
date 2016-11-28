#pragma once
#include "Item.h"
class Ring : public Item
{
public:
	Ring(string);
	~Ring();
	Ring();
	DECLARE_SERIAL(Ring)
	void Serialize(CArchive& archive);
private:
	static const string enchantmentTypes[];
};

