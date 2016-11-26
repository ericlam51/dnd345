#include "GodmodeChestView.h"
#undef max

//! method to create chest
void GodmodeChestView::newChestView() {

	string name, description;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter chest's name: " << endl;
	cin.ignore();
	getline(cin, name);
	

	cout << "Enter chest's description: " << endl;
	getline(cin, description);

	GodmodeChestController::instance()->newChest(name, description);
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

void GodmodeChestView::chestChooseSaveFileView(vector<string> filenames) {
	cout << "Please select one of the following files:" << endl;

	for (int i = 0; i < filenames.size(); i++) {
		cout << i + 1 << ". " << filenames[i] << endl;
	}

	cout << "Selection: ";

	int input;

	cin >> input;

	cin.clear(); //if cin fails because of wrong data type, clear error flag
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //clears the cin buffer

	GodmodeChestController::instance()->loadChest(input - 1);
}

void GodmodeChestView::chestAskSaveFileName() {
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeChestController::instance()->saveAndQuit(filename);
}

//! method show success creation message
void GodmodeChestView::warningMsgInvalidInput() {
	cout << "Invalid input" << endl;
}

//! method show success creation message
void GodmodeChestView::warningMsgChestLoaded() {
	cout << "Chest loaded" << endl;
}

//! method show success creation message
void GodmodeChestView::warningMsgChestSaved() {
	cout << "Chest saved" << endl;
}