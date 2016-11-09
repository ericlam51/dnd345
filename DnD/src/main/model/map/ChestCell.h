#pragma once
#include "Cell.h"

class ChestCell : public Cell
{
public:
	ChestCell();
	~ChestCell();
	bool interactable();
	bool walkable();
};

