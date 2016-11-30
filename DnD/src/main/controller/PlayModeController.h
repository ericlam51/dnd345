//! @file 
//! @brief Implementation file for the PlayModeController 
//!

#pragma once

#include "../view/map/godmode/GodmodeMapView.h"
#include "../model/map/Map.h"
#include "../model/map/Cell.h"
#include "../model/interactable/header/Active.h"

//! class for the implementation of play mode controller
//! this controller will handle the interaction between user and the software
class PlayModeController {
	// variable for the singleton 
	static PlayModeController *s_instance;
private:
	// A map object
	Map* map;
	// An active object ( the fighter )
	Active* _active;
	//method to load the Map
	void loadMap(string);
	//method to load the Fighter
	void loadFighter(string);

public:
	//! method to create or get the singleton class
	static PlayModeController* instance();
	//method to load the game
	void loadGame(string, string);
	//method to move the player
	void movePlayer(char direction);
	//method to print the map
	void printMap();
	//method to print the equipment
	void printEquipment();
};
