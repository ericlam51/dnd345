#include "GodmodeChestView.h"

void GodmodeChestView::newChestView() {

	string name, description;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter chest's name: " << endl;
	cin >> name;

	cout << "Enter chest's description: " << endl;
	cin >> description;

	GodmodeChestController::instance()->newChest(name, description);
}

void GodmodeChestView::loadChestView() {
	cout << "Loading chest..." << endl;
	GodmodeChestController::instance()->loadChest();
}

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

void GodmodeChestView::warningMsgChestLoaded() {
	cout << "Chest loaded" << endl;
}
void GodmodeChestView::saveAndQuitView(Chest* chest){
	cout << "Chest successfully created!" << endl;
	GodmodeChestController::instance()->saveAndQuit();
}