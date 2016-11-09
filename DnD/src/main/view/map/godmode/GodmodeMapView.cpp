#include "GodmodeMapView.h";

/* https://stackoverflow.com/questions/1904635/warning-c4003-and-errors-c2589-and-c2059-on-x-stdnumeric-limitsintmax/28102459#28102459 */
#undef max

void GodmodeMapView::fileOptionsMenuView() {
	int input = 0;

	cout << "------------------------------" << endl
		<< "1. New map" << endl
		<< "2. Load map" << endl
		<< "Selection: ";
	
	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer
	
	cout << "------------------------------" << endl;

	GodmodeMapController::instance()->mapFileSelection(input);
}

void GodmodeMapView::mapCreationInputView() {
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

void GodmodeMapView::warningMsgInvalidInput() {
	cout << "Invalid input!" << endl;
}

void GodmodeMapView::warningMsgChangingEntranceCell() {
	cout << "The previous entrance cell has been removed." << endl;
}

void GodmodeMapView::warningMsgChangingExitCell() {
	cout << "The previous exit cell has been removed." << endl;
}

void GodmodeMapView::mapOptionsMenuView() {
	int input;

	cout << "------------------------------" << endl
		<< "1. Fill cell" << endl
		<< "2. Validate map" << endl
		<< "3. Save map" << endl
		<< "Selection: ";

	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	cout << "------------------------------" << endl;

	GodmodeMapController::instance()->mapOptions(input);
}

void GodmodeMapView::warningMsgInvalidMap() {
	cout << "The map is invalid. To be a valid map, it must"
		<< "have an entrance and an exit cell, have a valid path between those two points"
		<< "and have all walkable cells be reachable (that is, all non-wall type)"
		<< endl;
}

void GodmodeMapView::warningMsgValidMap() {
	cout << "This is a valid map." << endl;
}

void GodmodeMapView::mapFillOptionsMenuView() {
	int x, y;
	int option;

	cout << "Please enter x coordinate: ";
	cin >> x;
	cout << "Please enter y coordinate: ";
	cin >> y;
	cout << "Pleae choose one of the following types (1, 2, 3, ...): " << endl
		<< "1. WALL (*)" << endl
		<< "2. START POINT (S)" << endl
		<< "3. EXIT POINT (D)" << endl
		<< "4. CHEST (C)" << endl
		<< "5. ENTITY (E)" << endl
		<< "6. EMPTY ( )" << endl
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
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::ENTITY_TYPE);
		break;
	case 6:
		GodmodeMapController::instance()->fillCell(x, y, CellHelper::PATH_TYPE);
		break;
	default: cout << "Invalid input"; break;
	}
}