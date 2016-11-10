#include "GodmodeFriendlyNpcView.h"

void GodmodeFriendlyNpcView::newFriendlyNpcView() {

	string name, description, dialog;

	ViewHelper::printDelimiter();

	cout << "Enter NPC's name: " << endl;
	cin >> name;

	cout << "Enter NPC's description: " << endl;
	cin >> description;

	cout << "Enter NPC's dialog: " << endl;
	cin >> dialog;

	GodmodeFriendlyNpcController::instance()->newFriendlyNpc(name, description, dialog);
}

void GodmodeFriendlyNpcView::postCreationView(){
	int input;

	ViewHelper::printDelimiter();

	cout << "Please select an option" << endl;
	cout << "1. Create another NPC" << endl
		 << "2. Save and Quit" << endl
		 << "Selection: ";

	cin >> input;
	GodmodeFriendlyNpcController::instance()->postCreation(input);
}

void GodmodeFriendlyNpcView::saveAndQuitView(FriendlyNpc* friendlyNpc){
	friendlyNpc->print();
	cout << "NPC successfully created!" << endl;
	GodmodeFriendlyNpcController::instance()->saveAndQuit();
}