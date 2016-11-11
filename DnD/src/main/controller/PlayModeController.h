#pragma once

#include "../view/map/godmode/GodmodeMapView.h"
#include "../model/map/Map.h"
#include "../model/map/Cell.h"
#include "../model/interactable/header/Active.h"

class PlayModeController {
	static PlayModeController *s_instance;
private:
	Map* map;
	Active* _active;
	void loadMap();
	void loadFighter();

public:
	static PlayModeController* instance();
	void loadGame();
	void movePlayer(char direction);
	void printMap();
	void printEquipment();
};
