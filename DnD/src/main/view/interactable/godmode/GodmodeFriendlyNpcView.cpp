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