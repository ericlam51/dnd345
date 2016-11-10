#pragma once
#include "Cell.h"
#include "../interactable/header/Interactable.h"

class EntityCell : public Cell
{
private:
	Interactable* entity;

public:
	EntityCell();
	~EntityCell();
	void setEntity(Interactable* entity);
	void setType(char type);
	bool interactable();
	bool walkable();
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(EntityCell);
};

