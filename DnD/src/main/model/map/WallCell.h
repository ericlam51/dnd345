#pragma once
#include "Cell.h"
//#include "../../helper/CellHelper.cpp"

class WallCell : public Cell
{
public:
	WallCell();
	~WallCell();
	bool interactable();
	bool walkable();
	inline char getType();
};

