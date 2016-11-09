#include "Map.h"

Map::Map(int width, int height) {
	this->width = width;
	this->height = height;
	
	initMap();
}

void Map::initMap() {
	//Init 2D array

	map = new Cell*[height];
	for (int y = 0; y < height; y++) {
		map[y] = new PathCell[width];

		for (int x = 0; x < width; x++) {
			map[y][x].setPosX(x);
			map[y][x].setPosY(y);
		}
	}

	//Init passed vector
	passed.resize(height, vector<bool>(width, false));
}

void Map::print() {
	cout << "========================================" << endl;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << map[y][x].getType();
		}
		cout << endl;
	}
	cout << "========================================" << endl;
}