#pragma once
#include "Item.h"
class Helmet : public Item
{
public:
	Helmet(string);
	~Helmet();
	Helmet();
	DECLARE_SERIAL(Helmet)
	void Serialize(CArchive& archive);
private:
	static const string enchantmentTypes[];
};

