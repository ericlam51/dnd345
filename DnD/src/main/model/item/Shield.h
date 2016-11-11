#pragma once
#include "Item.h"
class Shield : public Item
{
public:
	Shield(string);
	~Shield();
	Shield();
	DECLARE_SERIAL(Shield)
	void Serialize(CArchive& archive);
};

