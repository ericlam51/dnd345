#pragma once

#include "../../../view/map/godmode/GodmodeMapView.h"
#include "../../../view/GameModeView.h"
#include "../../../model/map/Map.h"
#include "../../../model/map/Cell.h"

class GodmodeMapController {
	static GodmodeMapController *s_instance;
private:
	Map* map;
	void setCell(int x, int y, Cell* cell);
	vector<string> filenames;

public:
	static GodmodeMapController* instance();
	void mapFileSelection(int input);
	void newMap(int width, int height);
	void fillCell(int x, int y, char cellType);
	void mapOptions(int input);
	void validateMap();
	void getSavedMapFiles();
	void validateSaveRequirements();

	void saveMap(string filename);
	void loadMap(int inpu);

	void print();

	void resetController();
};