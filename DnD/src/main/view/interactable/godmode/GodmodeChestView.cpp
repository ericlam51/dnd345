#include "GodmodeChestView.h"

void GodmodeChestView::newChestView() {

	string name, description;

	ViewHelper::printDelimiter();

	cout << "Enter chest's name: " << endl;
	cin >> name;

	cout << "Enter chest's description: " << endl;
	cin >> description;

	GodmodeChestController::instance()->newChest(name, description);
}

void GodmodeChestView::postCreationView(){
	int input;

	ViewHelper::printDelimiter();

	cout << "Please select an option" << endl;
	cout << "1. Create another Chest" << endl
		 << "2. Save and Quit" << endl
		 << "Selection: ";

	cin >> input;
	GodmodeChestController::instance()->postCreation(input);
}

void GodmodeChestView::saveAndQuitView(Chest* chest){
	cout << "Chest successfully created!" << endl;
	GodmodeChestController::instance()->saveAndQuit();
}