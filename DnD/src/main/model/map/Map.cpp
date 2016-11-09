#include "Map.h"

Map::Map(int width, int height) {
	this->width = width;
	this->height = height;
	
	initMap();
}

void Map::initMap() {
	//Init 2D array

	map.resize(height, vector<Cell*>(width));

	for (int y = 0; y < height; y++) {
	
		for (int x = 0; x < width; x++) {
			map[y][x] = new PathCell();
			map[y][x]->setPosX(x);
			map[y][x]->setPosY(y);
		}
	}

	//Init passed vector
	passed.resize(height, vector<bool>(width, false));
}

void Map::print() {
	cout << "========================================" << endl;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			char tpe = map[y][x]->getType();
			cout << tpe;
		}
		cout << endl;
	}
	cout << "========================================" << endl;
}

void Map::fillCell(int x, int y, Cell* cell) {
	if (cell->getType() == CellHelper::ENTRANCE_TYPE) {
		if (startingCell != NULL) {
			int previousStartingX = startingCell->getPosX();
			int previousStartingY = startingCell->getPosY();
			map[previousStartingY][previousStartingY] = new PathCell();

			delete startingCell;
			startingCell = cell;
		}

		startingCell = cell;
	}

	if (cell->getType() == CellHelper::ENTRANCE_TYPE) {
		if (exitCell != NULL) {
			int previousExitX = startingCell->getPosX();
			int previousExitY = startingCell->getPosY();
			map[previousExitY][previousExitX] = new PathCell();

			delete exitCell;
			exitCell = cell;
		}

		exitCell = cell;
	}

	Cell* currentCell = map[y][x];
	map[y][x] = NULL;
	delete currentCell;

	cell->setPosX(x);
	cell->setPosY(y);
	map[y][x] = cell;
}