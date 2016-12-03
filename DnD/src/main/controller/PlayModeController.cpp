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
void PlayModeController :: loadGame(string mapInput, string fighterInput) {
	PlayModeController::loadFighter(fighterInput);
	PlayModeController::loadMap(mapInput);
}

//! method to load the map
void PlayModeController::loadMap(string input) {
	Logger::instance()->appendToNewLine("Loading map from " + input, "GAMECONTROLLER");
	CFile theFile;
	string filePath = FileHelper::getDirectoryPath(FileHelper::MAP_FILE_FOLDER) + input;
	theFile.Open(_T(filePath.c_str()), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	map = new Map();
	map->Serialize(archive);
	s_instance->map = map;

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
		/*int input = 0;
		while (input < 1 || input >2) {
			cout << "Do you want to interact with the cell?" << endl
				<< "1. Yes" << endl
				<< "2. No" << endl;
			cin >> input;
		}
		if (input == 2)
			return;*/

		map->interact(direction);
		int x = map->getNextDirectionX(direction);
		int y = map->getNextDirectionY(direction);

		map->fillCell(x, y, new PathCell());

	}
	bool validateWalkable = map->getNextCellWalkability(direction);
	if (validateWalkable) {
		map->movePlayer(direction);
	}

}

void PlayModeController::printEquipment() {
	Logger::instance()->appendToNewLine("Printing equipment", "GAMECONTROLLER");
	string input;
	_active->printEquipments();
	_active->print();
	_active->printInventory();
	cout << "Type anything to exit" << endl;
	cin >> input;
}

void PlayModeController::itemSelection() {
	char input;
	_active->printInventory();

	bool cont = true;
	while (cont) {
		char item;
		cout << "Choose an item to equip : (h: helmet, a: armor, s: shield, r: ring, j: boots, w: weapon" << endl;
		cin >> item;

		equipFromInventory(item);

		cout << "Do you want to continue to equip item? ([Y/n])" << endl;
		cin >> input;

		if (input == 'y' || input == 'Y')
			cont = true;

		if (input == 'n' || input == 'N')
			cont = false;
	}

}

void PlayModeController::equipFromInventory(char item) {
	switch (item) {
	case 'h':
	{
		vector<Item*> helmets = _active->getInventory()->getItemsOfType(ItemTypes[HELMET]);
		if (helmets.size() == 0)
		{
			cout << endl << "No items of type: Helmet" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a Helmet to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > helmets.size());
			
			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[HELMET], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	case 'a':
	{
		vector<Item*> armors = _active->getInventory()->getItemsOfType(ItemTypes[ARMOR]);
		if (armors.size() == 0)
		{
			cout << endl << "No items of type: armors" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a armor to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > armors.size());

			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[ARMOR], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	case 's':
	{
		vector<Item*> shields = _active->getInventory()->getItemsOfType(ItemTypes[SHIELD]);
		if (shields.size() == 0)
		{
			cout << endl << "No items of type: shields" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a shield to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > shields.size());

			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[SHIELD], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	case 'r':
	{
		vector<Item*> rings = _active->getInventory()->getItemsOfType(ItemTypes[RING]);
		if (rings.size() == 0)
		{
			cout << endl << "No items of type: shields" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a shield to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > rings.size());

			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[RING], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	case 'j':
	{
		vector<Item*> boots = _active->getInventory()->getItemsOfType(ItemTypes[BOOTS]);
		if (boots.size() == 0)
		{
			cout << endl << "No items of type: boot" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a boot to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > boots.size());

			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[BOOTS], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	case 'w':
	{
		vector<Item*> weapons = _active->getInventory()->getItemsOfType(ItemTypes[WEAPON]);
		if (weapons.size() == 0)
		{
			cout << endl << "No items of type: weapon" << endl;
		}
		else
		{
			int index;
			cout << endl << "Select a weapon to equip: " << endl;
			do {
				cin >> index;
			} while (index < 0 || index > weapons.size());

			Item* itemToEquip = _active->getInventory()->getItem(ItemTypes[WEAPON], index - 1);
			_active->removeFromInventory(itemToEquip);
			_active->equipItem(itemToEquip);
		}
	}
	break;
	default:
		cout << "Failed to equip." << endl;
	}
}
//!method to load fighter
void PlayModeController::loadFighter(string input) {
	Logger::instance()->appendToNewLine("Loading fighter from " + input, "GAMECONTROLLER");
	CFile theFile;
	string filePath = FileHelper::getDirectoryPath(FileHelper::FIGHTER_FILE_FOLDER) + input;
	theFile.Open(_T(filePath.c_str()), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	_active = new Fighter();
	_active->Serialize(archive);
	s_instance->_active = _active;
	archive.Close();
	theFile.Close();
}

void PlayModeController::endGame() {
	GameModeView::endGame();
}
