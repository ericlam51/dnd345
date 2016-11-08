#include "GodmodeMapView.h";

void GodmodeMapView::mapFileSelectionView() {
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

void GodmodeMapView::mapCreationParamSelectionView() {
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

void GodmodeMapView::invalidInputView() {
	cout << "Invalid input!" << endl;
}