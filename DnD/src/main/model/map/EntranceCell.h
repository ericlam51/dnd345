#pragma once
#include "Cell.h"

class EntranceCell : public Cell
{
public:
	EntranceCell();
	~EntranceCell();
	bool interactable();
	bool walkable();
};

