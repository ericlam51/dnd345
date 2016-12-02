//! @file 
//! @brief Implementation file for GodmodeMapView
//!

#include "GodmodeMapView.h"

/* https://stackoverflow.com/questions/1904635/warning-c4003-and-errors-c2589-and-c2059-on-x-stdnumeric-limitsintmax/28102459#28102459 */
#undef max

//! Show options to load or create map
void GodmodeMapView::fileOptionsMenuView() {
	std::stringstream log;
	log << "Display main view for god mode map";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	int input = 0;

	cout << "------------------------------" << endl
		<< "1. New map" << endl
		<< "2. Load map" << endl
		<< "3. Return to Selection menu" << endl
		<< "Selection: ";
	
	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer
	
	cout << "------------------------------" << endl;

	GodmodeMapController::instance()->mapFileSelection(input);
}

//! Ask user for map parameters creation
void GodmodeMapView::mapCreationInputView() {
	std::stringstream log;
	log << "Display map creation size input view";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	int width = 0, height = 0;

	cout << "------------------------------" << endl
		<< "Please input the map width: " << endl;
	cin >> width;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	cout << "Please input the map height: " << endl;
	cin >> height;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	cout << "------------------------------" << endl;


	GodmodeMapController::instance()->newMap(width, height);
}

void GodmodeMapView::mapChooseSaveMapFileView(vector<string> filenames) {
	if (filenames.size() == 0) {
		cout << "No files created. Please create some first" << endl;
		return;
	}

	std::stringstream log;
	log << "Display map load file selection view";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << "Please select one of the following files:" << endl;

	for (int i = 0; i < filenames.size(); i++) {
		cout << i+1 << ". " << filenames[i] << endl;
	}

	cout << "Selection: ";

	int input;

	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	GodmodeMapController::instance()->loadMap(input-1);
}

//! Show options to edit the map
void GodmodeMapView::mapOptionsMenuView() {
	std::stringstream log;
	log << "Display map editor view";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	int input;

	cout << "------------------------------" << endl
		<< "1. Fill cell" << endl
		<< "2. Validate map" << endl
		<< "3. Save map" << endl
		<< "4. Return to Selection menu" << endl
		<< "Selection: ";

	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	cout << "------------------------------" << endl;

	GodmodeMapController::instance()->mapOptions(input);
}

//! Show options to fill a cell on the map
void GodmodeMapView::mapFillOptionsMenuView() {
	std::stringstream log;
	log << "Display cell editor view";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	int x, y;
	int option;

	cout << "Please enter x coordinate: ";
	cin >> x;
	cout << "Please enter y coordinate: ";
	cin >> y;
	cout << "Pleae choose one of the following types (1, 2, 3, ...): " << endl
		<< "1. WALL (*)" << endl
		<< "2. START POINT (S)" << endl
		<< "3. EXIT POINT (E)" << endl
		<< "4. CHEST (C)" << endl
		<< "5. ENTITY ENEMY (X)" << endl
		<< "6. ENTITY NPC (N)" << endl
		<< "7. EMPTY ( )" << endl
		<< "Option: ";
	cin >> option;

	switch (option) {
	case 1:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::WALL_TYPE);
		break;
	case 2:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::ENTRANCE_TYPE);
		break;
	case 3:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::EXIT_TYPE);
		break;
	case 4:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::CHEST_TYPE);
		break;
	case 5:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::ENTITY_TYPE, 1);
		break;
	case 6:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::ENTITY_TYPE, 2);
		break;
	case 7:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::PATH_TYPE);
		break;
	default: 
		GodmodeMapController::instance()->fillCell(x, y, NULL);
		break;
	}
}

void GodmodeMapView::mapAskSaveFileName() {
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeMapController::instance()->saveMap(filename);
}

/* WARNING MESSAGES */

void GodmodeMapView::warningMsgInvalidInput() {
	std::stringstream log;
	log << "Map view: invalid input";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << "Invalid input!" << endl;
}

void GodmodeMapView::warningMsgChangingEntranceCell() {
	string msg = "The previous entrance cell has been removed.";

	std::stringstream log;
	log << msg;
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << msg << endl;
}

void GodmodeMapView::warningMsgChangingExitCell() {
	string msg = "The previous exit cell has been removed.";

	std::stringstream log;
	log << msg;
	Logger::instance()->appendToNewLine(log.str(), "MAP");
	
	cout << msg << endl;

}

void GodmodeMapView::warningMsgInvalidMap() {
	std::stringstream log;
	log << "Map is invalid";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << "The map is invalid. To be a valid map, it must"
		<< "have an entrance and an exit cell, have a valid path between those two points"
		<< "and have all walkable cells be reachable (that is, all non-wall type)"
		<< endl;
}

void GodmodeMapView::warningMsgValidMap() {
	std::stringstream log;
	log << "Map is valid";
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << "This is a valid map." << endl;
}


void GodmodeMapView::warningMsgMapSaved() {
	string msg = "Map saved";

	std::stringstream log;
	log << msg;
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << msg << endl;
}

void GodmodeMapView::warningMsgMapLoaded() {
	string msg = "Map loaded";

	std::stringstream log;
	log << msg;
	Logger::instance()->appendToNewLine(log.str(), "MAP");

	cout << msg << endl;
}

void GodmodeMapView::warningMsgWrongCoordinates() {
	cout << "Coordinates inputted will go out of the map." << endl;
}

void GodmodeMapView::warningMsgWrongCellType() {
	cout << "Input for cell type does not exist." << endl;
}