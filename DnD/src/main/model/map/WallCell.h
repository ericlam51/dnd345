#pragma once
#include "Cell.h"

class WallCell : public Cell
{
public:
	WallCell();
	~WallCell();
	bool iterable();
	bool walkable();
	inline bool getType();
};

