#pragma once

#include "../../../view/map/godmode/GodmodeMapView.h";
#include "../../../model/map/Map.h"

class GodmodeMapController {
	static GodmodeMapController *s_instance;
private:
	Map* map;

public:
	static GodmodeMapController* instance();
	void mapFileSelection(int input);
	void newMap(int width, int height);
};