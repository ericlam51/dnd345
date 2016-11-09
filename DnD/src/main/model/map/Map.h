#pragma once

#include "Cell.h"
#include "PathCell.h"
#include "WallCell.h"
#include <vector>
#include <iostream>

using namespace std;

class Map {
private:
	int height, width;
	//vector<vector<Cell>> map;
	Cell** map;
	vector<vector<bool>> passed;

	void initMap();

public:
	Map(int width, int height);
	~Map();

	/* GODMODE SPECIFIC */
	void fillCell(int x, int y, Cell* cell);
	void print();
	bool validateMap();

	/* PLAYER SPECIFIC */
};