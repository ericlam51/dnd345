#include "GodmodeChestView.h"

//! method to create chest
void GodmodeChestView::newChestView() {

	string name, description;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter chest's name: " << endl;
	cin >> name;

	cout << "Enter chest's description: " << endl;
	cin >> description;

	GodmodeChestController::instance()->newChest(name, description);
}

//! method to load chest
void GodmodeChestView::loadChestView() {
	cout << "Loading chest..." << endl;
	GodmodeChestController::instance()->loadChest();
}

//! method to create chest another chest or save and quit
void GodmodeChestView::postCreationView(){
	int input;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Please select an option" << endl;
	cout << "1. Create another Chest" << endl
		 << "2. Save and Quit" << endl
		 << "Selection: ";

	cin >> input;
	GodmodeChestController::instance()->postCreation(input);
}


//! method show success creation message
void GodmodeChestView::warningMsgChestLoaded() {
	cout << "Chest loaded" << endl;
}

//! method to s save and quit
void GodmodeChestView::saveAndQuitView(Chest* chest){
	cout << "Chest successfully created!" << endl;
	chest->print();
	GodmodeChestController::instance()->saveAndQuit();
}