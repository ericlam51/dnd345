/**
* Controller for everything related to the Map in God mode. The controller is called by the views. Whenever, there is some activity
* on the view, the actual logic is done in the controller. In return, the controller will call different views depending on the
* result of said logic processing. 
*/
#pragma once

#include "../../../view/map/godmode/GodmodeMapView.h"
#include "../../../model/map/Map.h"
#include "../../../model/map/Cell.h"

class GodmodeMapController {
	static GodmodeMapController *s_instance;
private:
	Map* map;
	void setCell(int x, int y, Cell* cell);

public:
	static GodmodeMapController* instance();
	void mapFileSelection(int input);
	void newMap(int width, int height);
	void fillCell(int x, int y, char cellType);
	void mapOptions(int input);
	void validateMap();

	void saveMap();
	void loadMap();

	void print();
};