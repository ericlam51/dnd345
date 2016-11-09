#include "GodmodeFighterView.h"

void GodmodeFighterView::newfighterView() {

	string name, description;
	int level;

	ViewHelper::printDelimiter();

	cout << "Enter character's name: " << endl;
	cin >> name;

	cout << "Enter character's description: " << endl;
	cin >> description;

	cout << "Enter character's level: " << endl;
	cin >> level;

	GodmodeFighterController::instance()->newFighter(name, description, level);
}