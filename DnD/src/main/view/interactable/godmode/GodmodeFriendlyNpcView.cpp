#include "GodmodeFriendlyNpcView.h"
#undef max
//! method to create NPC
void GodmodeFriendlyNpcView::newFriendlyNpcView() {

	string name, description, dialog;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter NPC's name: " << endl;
	cin.ignore();
	getline(cin, name);

	cout << "Enter NPC's description: " << endl;
	getline(cin, description);

	cout << "Enter NPC's dialog: " << endl;
	getline(cin, dialog);


	GodmodeFriendlyNpcController::instance()->newFriendlyNpc(name, description, dialog);
}

//! method to create another NPC or save and quit
void GodmodeFriendlyNpcView::postCreationView(){
	int input;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Please select an option" << endl;
	cout << "1. Create another NPC" << endl
		<< "2. Save and Quit" << endl;

	do {
		cout << "Selection: " << endl;
		cin.clear();
		cin >> input;
	} while (input < 1 || input > 2);
	
	GodmodeFriendlyNpcController::instance()->postCreation(input);
}
void GodmodeFriendlyNpcView::friendlyChooseSaveFileView(vector<string> filenames) {
	cout << "Please select one of the following files:" << endl;
	int input;
	for (int i = 0; i < filenames.size(); i++) {
		cout << i + 1 << ". " << filenames[i] << endl;
	}

	do {
		cout << "Selection: " << endl;
		cin.clear();
		cin >> input;
	} while (input < 1 || input > filenames.size());


	GodmodeFriendlyNpcController::instance()->loadFriendlyNpc(input - 1);
}

void GodmodeFriendlyNpcView::friendlyAskSaveFileName() {
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeFriendlyNpcController::instance()->saveAndQuit(filename);
}

void GodmodeFriendlyNpcView::warningMsgInvalidInput(){
	cout << "Invalid input" << endl;
}

void GodmodeFriendlyNpcView::warningMsgFriendlySaved(){
	cout << "NPC saved!" << endl;
}

void GodmodeFriendlyNpcView::warningMsgFriendlyLoaded(){
	cout << "NPC loaded!" << endl;
}