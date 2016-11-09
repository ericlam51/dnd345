#pragma once

#include "Cell.h"
#include "PathCell.h"
#include "WallCell.h"
#include <vector>
#include <iostream>
#include <afx.h>

using namespace std;

class Map : public CObject{
private:
	int height, width;
	vector<vector<Cell*>> map;
	//Cell** map;
	vector<vector<bool>> passed;
	Cell* startingCell = NULL;
	Cell* exitCell = NULL;

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

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Map);

	/* PLAYER SPECIFIC */
	
};