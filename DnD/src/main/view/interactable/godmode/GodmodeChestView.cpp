#include "GodmodeChestView.h"

void GodmodeChestView::newChestView() {

	string name, description;
	int level;

	ViewHelper::printDelimiter();

	cout << "Enter chest's name: " << endl;
	cin >> name;

	cout << "Enter chest's description: " << endl;
	cin >> description;

	GodmodeChestController::instance()->newChest(name, description);
}