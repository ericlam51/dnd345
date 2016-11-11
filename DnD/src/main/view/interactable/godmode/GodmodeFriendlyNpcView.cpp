#include "GodmodeFriendlyNpcView.h"

//! method to create NPC
void GodmodeFriendlyNpcView::newFriendlyNpcView() {

	string name, description, dialog;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter NPC's name: " << endl;
	cin >> name;

	cout << "Enter NPC's description: " << endl;
	cin >> description;

	cout << "Enter NPC's dialog: " << endl;
	cin >> dialog;

	GodmodeFriendlyNpcController::instance()->newFriendlyNpc(name, description, dialog);
}

//! method to load NPC
void GodmodeFriendlyNpcView::loadFriendlyNpcView() {
	cout << "Loading NPC..." << endl;
	GodmodeFriendlyNpcController::instance()->loadFriendlyNpc();
}

//! method to create another NPC or save and quit
void GodmodeFriendlyNpcView::postCreationView(){
	int input;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Please select an option" << endl;
	cout << "1. Create another NPC" << endl
		 << "2. Save and Quit" << endl
		 << "Selection: ";

	cin >> input;
	GodmodeFriendlyNpcController::instance()->postCreation(input);
}

//! method to show NPC successfully loaded
void GodmodeFriendlyNpcView::warningMsgFriendlyNpcLoaded() {
	cout << "NPC loaded" << endl;
}

//! method to save Npc and quit
void GodmodeFriendlyNpcView::saveAndQuitView(FriendlyNpc* friendlyNpc){
	friendlyNpc->print();
	cout << "NPC successfully created!" << endl;
	GodmodeFriendlyNpcController::instance()->saveAndQuit();
}