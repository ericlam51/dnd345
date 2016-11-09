#pragma once
#include "Cell.h"

class ExitCell : public Cell
{
public:
	ExitCell();
	~ExitCell();
	bool interactable();
	bool walkable();
};

