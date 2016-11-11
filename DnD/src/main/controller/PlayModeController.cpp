//! @file 
//! @brief Implementation file for the PlayModeController
//!

#include "PlayModeController.h"
//! Constructor for the singleton PlayModeController 
PlayModeController* PlayModeController::instance() {
	if (!s_instance)
		s_instance = new PlayModeController();

	return s_instance;
}
// Initialize the singleton instance
PlayModeController* PlayModeController::s_instance = PlayModeController::instance();

//! method to load the game
void PlayModeController :: loadGame() {
	PlayModeController::loadMap();
	PlayModeController::loadFighter();
}

//! method to load the map
void PlayModeController::loadMap() {
	CFile theFile;
	theFile.Open(_T("Map.txt"), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	map = new Map();
	map->Serialize(archive);

	archive.Close();
	theFile.Close();

	map->startMap(_active);

}

//! method to print the map
void PlayModeController::printMap() {
	map->print();
}

//! method to move the player
//!@param direction: a character that represents the direction the player is moving toward, U for Up, L for Left, R for Right, and D for Down
void PlayModeController::movePlayer(char direction) {
	bool validateInteractable = map->getNextCellInteractibility(direction);
	if (validateInteractable) {
		int input = 0;
		while (input < 1 || input >2) {
			cout << "Do you want to interact with the cell?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl;
			cin >> input;
		}
		if (input == 2)
			return;
		map->interact(direction);

	}
	bool validateWalkable = map->getNextCellWalkability(direction);
	if (validateWalkable) {
		map->movePlayer(direction);
	}

}

void PlayModeController::printEquipment() {
	string input;
	//_active->printEquipments();
	_active->print();
	cout << "Type anything to exit" << endl;
	cin >> input;
}

//!method to load fighter
void PlayModeController::loadFighter() {
	CFile theFile;
	theFile.Open(_T("Fighter"), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	_active = new Fighter();
	_active->Serialize(archive);

	archive.Close();
	theFile.Close();
}
