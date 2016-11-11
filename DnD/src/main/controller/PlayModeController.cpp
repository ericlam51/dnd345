#include "PlayModeController.h"

PlayModeController* PlayModeController::instance() {
	if (!s_instance)
		s_instance = new PlayModeController();

	return s_instance;
}

PlayModeController* PlayModeController::s_instance = PlayModeController::instance();

void PlayModeController :: loadGame() {
	PlayModeController::loadMap();
	PlayModeController::loadFighter();
}

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
void PlayModeController::printMap() {
	map->print();
}
void PlayModeController::movePlayer(char direction) {
	bool validateInteractable = map->getNextCellInteractibility(direction);
	if (validateInteractable) {
		int input = 0;
		while (input < 0 || input >2) {
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
	_active->printEquipments();
}

void PlayModeController::loadFighter() {
	CFile theFile;
	theFile.Open(_T("Fighter"), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	_active = new Fighter();
	_active->Serialize(archive);

	archive.Close();
	theFile.Close();
}