#pragma once
#include "Cell.h"
#include "../interactable/header/Interactable.h"
#include "../interactable//header/Chest.h"

class ChestCell : public Cell
{
private:
	Interactable* chest;
public:
	ChestCell();
	~ChestCell();
	void setChest(Interactable* chest);
	bool interactable();
	bool walkable();
	void Serialize(CArchive& archive);
	void interact();
	DECLARE_SERIAL(ChestCell);
};

