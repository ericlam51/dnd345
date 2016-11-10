#pragma once
#include "Cell.h"

class PathCell : public Cell
{
public:
	PathCell();
	~PathCell();
	bool interactable();
	bool walkable();
	void Serialize(CArchive& archive);
	void interact();
	DECLARE_SERIAL(PathCell);
};

