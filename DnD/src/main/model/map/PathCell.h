#pragma once
#include "Cell.h"

class PathCell : public Cell
{
public:
	PathCell();
	~PathCell();
	bool interactable();
	bool walkable();
};

