#include "Map.h"
#include "../../view/map/godmode/GodmodeMapView.h"

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
	
	cout << "=";
	for (int i = 0; i < width; i++) {
		cout << "=";
	}
	cout << "=";
	cout << endl;

	for (int y = 0; y < height; y++) {
		cout << "|";
		for (int x = 0; x < width; x++) {
			char tpe = map[y][x]->getType();
			cout << tpe;
		}
		cout << "|" << endl;
	}
	
	cout << "=";
	for (int i = 0; i < width; i++) {
		cout << "=";
	}
	cout << "=";
	cout << endl;
	cout << "========================================" << endl;
}

void Map::fillCell(int x, int y, Cell* cell) {
	if (cell->getType() == CellHelper::ENTRANCE_TYPE) {
		if (startingCell != NULL) {
			GodmodeMapView::warningMsgChangingEntranceCell();
			int previousStartingX = startingCell->getPosX();
			int previousStartingY = startingCell->getPosY();
			map[previousStartingY][previousStartingX] = new PathCell();

			delete startingCell;
			startingCell = cell;
		}

		startingCell = cell;
	}

	if (cell->getType() == CellHelper::EXIT_TYPE) {
		if (exitCell != NULL) {
			GodmodeMapView::warningMsgChangingExitCell();
			int previousExitX = startingCell->getPosX();
			int previousExitY = startingCell->getPosY();
			map[previousExitY][previousExitX] = new PathCell();

			delete exitCell;
			exitCell = cell;
		}

		exitCell = cell;
	}

	if (startingCell != NULL) {
		if ((startingCell->getPosX() == x && startingCell->getPosY() == y)) {
			startingCell = NULL;
		}
	}

	if (exitCell != NULL) {
		if ((exitCell->getPosX() == x && exitCell->getPosY() == y)) {
			exitCell = NULL;
		}
	}

	

	Cell* currentCell = map[y][x];
	map[y][x] = NULL;
	delete currentCell;

	cell->setPosX(x);
	cell->setPosY(y);
	map[y][x] = cell;
}

bool Map::validateMap() {
	if (startingCell == NULL || exitCell == NULL) {
		return false;
	}

	resetPassed();

	int startX = startingCell->getPosX();
	int startY = startingCell->getPosY();

	bool validPath = isPathValid(startX, startY, startX, startY);

	if (!validPath) {
		return false;
	}

	resetPassed();

	bool allWalkableCellsAccessible = isAllWalkableCellsAccessible();

	if (!allWalkableCellsAccessible) {
		return false;
	}

	return true;
}

bool Map::isAllWalkableCellsAccessible() {
	int startX = startingCell->getPosX();
	int startY = startingCell->getPosY();

	bool done = walkThroughMap(startX, startY, startX, startY);
	bool valid = true;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (map[y][x]->walkable() != passed[y][x]) {
				valid = false;
				break;
			}
		}
	}

	return valid;
}

bool Map::walkThroughMap(int x, int y, int prevX, int prevY) {
	if (!passed[y][x]) {
		passed[y][x] = true;
	}

	//Down
	if (y + 1 < height && (y + 1 != prevY || x != prevX)) {
		if (!passed[y + 1][x]) {
			if (map[y + 1][x]->getType() != CellHelper::WALL_TYPE) {

				if (walkThroughMap(x, y + 1, x, y)) {
					return true;
				}
			}
		}
	}

	//Right
	if (x + 1 < width && (x + 1 != prevX || y != prevY)) {
		if (!passed[y][x + 1]) {
			if (map[y][x + 1]->getType() != CellHelper::WALL_TYPE) {
				if (walkThroughMap(x + 1, y, x, y)) {
					return true;
				}
			}
		}
	}

	//Up
	if (y - 1 >= 0 && (y - 1 != prevY || x != prevX)) {
		if (!passed[y - 1][x]) {
			if (map[y - 1][x]->getType() != CellHelper::WALL_TYPE) {
				if (walkThroughMap(x, y - 1, x, y)) {
					return true;
				}
			}
		}
	}

	//Left
	if (x - 1 >= 0 && (x - 1 != prevX || y != prevY)) {
		if (!passed[y][x - 1]) {
			if (map[y][x - 1]->getType() != CellHelper::WALL_TYPE) {
				if (walkThroughMap(x - 1, y, x, y)) {
					return true;
				}
			}
		}

	}

	return false;
}

bool Map::isPathValid(int x, int y, int prevX, int prevY) {
	if (!passed[y][x]) {
		passed[y][x] = true;
	}

	if (map[y][x]->getType() == CellHelper::EXIT_TYPE) {
		return true;
	}

	//Down
	if (y + 1 < height && (y + 1 != prevY || x != prevX)) {
		if (!passed[y + 1][x]) {
			if (map[y + 1][x]->getType() != CellHelper::WALL_TYPE) {

				if (isPathValid(x, y + 1, x, y)) {
					return true;
				}
			}
		}
	}

	//Right
	if (x + 1 < width && (x + 1 != prevX || y != prevY)) {
		if (!passed[y][x + 1]) {
			if (map[y][x + 1]->getType() != CellHelper::WALL_TYPE) {
				if (isPathValid(x + 1, y, x, y)) {
					return true;
				}
			}
		}
	}

	//Up
	if (y - 1 >= 0 && (y - 1 != prevY || x != prevX)) {
		if (!passed[y - 1][x]) {
			if (map[y - 1][x]->getType() != CellHelper::WALL_TYPE) {
				if (isPathValid(x, y - 1, x, y)) {
					return true;
				}
			}
		}
	}

	//Left
	if (x - 1 >= 0 && (x - 1 != prevX || y != prevY)) {
		if (!passed[y][x - 1]) {
			if (map[y][x - 1]->getType() != CellHelper::WALL_TYPE) {
				if (isPathValid(x - 1, y, x, y)) {
					return true;
				}
			}
		}

	}

	return false;
}

void Map::resetPassed() {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			passed[y][x] = false;
		}
	}
}