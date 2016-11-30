#pragma once
#include "Cell.h"
#include "../interactable/header/Interactable.h"
#include "../interactable/header/HostileNpc.h"

class EntityCell : public Cell
{
private:
	Interactable* entity;
	bool isFriendly;

public:
	EntityCell();
	EntityCell(bool isFriendly);
	~EntityCell();
	void setEntity(Interactable* entity);
	void setType(char type);
	bool interactable();
	bool walkable();
	bool getIsFriendly();
	void Serialize(CArchive& archive);
	void interact();
	char printType();
	DECLARE_SERIAL(EntityCell);
};

