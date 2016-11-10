#pragma once

#include "Cell.h"
#include "PathCell.h"
#include "WallCell.h"
#include "ChestCell.h"
#include "ExitCell.h"
#include "EntranceCell.h"
#include "EntityCell.h"
#include <vector>
#include <iostream>
#include <afx.h>
#include <algorithm>

using namespace std;

class Map : public CObject{
private:
	int height, width;
	int chestSize, entitySize, wallSize, pathSize;
	vector<vector<Cell*>> map;

	vector<PathCell*> pathCells;
	vector<EntityCell*> entityCells;
	vector<WallCell*> wallCells;
	vector<ChestCell*> chestCells;

	EntranceCell* startingCell = NULL;
	ExitCell* exitCell = NULL;

	//Cell** map;
	vector<vector<bool>> passed;
	

	void initMap();
	void resetPassed();
	bool isPathValid(int x, int y, int prevX, int prevY);
	bool isAllWalkableCellsAccessible();
	bool walkThroughMap(int x, int y, int prevX, int prevY);

	void addPathCell(Cell* cell);
	void removePathCell(int x, int y);
	void addWallCell(Cell* cell);
	void removeWallCell(int x, int y);
	void addEntityCell(Cell* cell);
	void removeEntityCell(int x, int y);
	void addChestCell(Cell* cell);
	void removeChestCell(int x, int y);
	void changeStartingCell(Cell* cell);
	void removeStartingCell(int x, int y);

public:
	Map();
	Map(int width, int height);
	~Map();

	/* GODMODE SPECIFIC */
	void fillCell(int x, int y, Cell* cell);
	void print();
	bool validateMap();

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Map);
	
};