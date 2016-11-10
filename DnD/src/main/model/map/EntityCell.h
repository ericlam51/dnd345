#pragma once
#include "Cell.h"

class EntityCell : public Cell
{
public:
	EntityCell();
	~EntityCell();
	bool interactable();
	bool walkable();
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(EntityCell);
};

