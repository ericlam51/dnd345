#include "GodmodeHostileNpcView.h"

void GodmodeHostileNpcView::newHostileNpctView() {

	string name, description, dialog;
	int level;

	ViewHelper::printDelimiter();

	cout << "Enter monster's name: " << endl;
	cin >> name;

	cout << "Enter monster's description: " << endl;
	cin >> description;

	cout << "Enter monster's dialog: " << endl;
	cin >> level;

	GodmodeHostileNpcController::instance()->newHostileNpc(name, description, level);
}