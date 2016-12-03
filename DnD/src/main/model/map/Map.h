#pragma once

#include "Cell.h"
#include "PathCell.h"
#include "WallCell.h"
#include "ChestCell.h"
#include "ExitCell.h"
#include "EntranceCell.h"
#include "EntityCell.h"
#include "../interactable/header/Fighter.h"
#include <vector>
#include <iostream>
#include <afx.h>
#include <algorithm>

using namespace std;

class Map : public CObject{
private:
	int height, width;
	vector<vector<Cell*>> map;
	EntityCell* playerCell;
	Cell* cachedCell;

	/* SERIALIZE RELATED */
	int chestSize, entitySize, wallSize, pathSize;
	vector<PathCell*> pathCells;
	vector<EntityCell*> entityCells;
	vector<WallCell*> wallCells;
	vector<ChestCell*> chestCells;

	/* VALIDATION RELATED*/
	EntranceCell* startingCell = NULL;
	ExitCell* exitCell = NULL;
	vector<vector<bool>> passed;
	bool validateOutofBound(int x, int y);
	void initMap();
	void resetPassed();
	bool isPathValid(int x, int y, int prevX, int prevY);
	bool isAllWalkableCellsAccessible();
	bool walkThroughMap(int x, int y, int prevX, int prevY);

public:
	Map();
	Map(int width, int height);
	~Map();

	/* GODMODE SPECIFIC */
	void fillCell(int x, int y, Cell* cell);
	void print();
	bool validateMap();

	/* PLAYERMODE SPECIFIC */
	void movePlayer(char side);
	void interact(char side);
	void startMap(Interactable* fighter);
	bool getNextCellInteractibility(char side);
	bool getNextCellWalkability(char side);
	int getNextDirectionX(char direction);
	int getNextDirectionY(char direction);

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Map);

	int getWidth();
	int getHeight();
	
};