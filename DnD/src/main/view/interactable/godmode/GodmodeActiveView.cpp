#include "GodmodeActiveView.h"

string GodmodeActiveView::typeStr = "";

void GodmodeActiveView::newActiveView(int type) {

	string name, description;
	int level;

	ViewHelper::printDelimiter();

	if(type == 0)
		typeStr = "Fighter";
	else if (type == 1)
		typeStr = "Monster";

	cout << "Enter " << typeStr <<"'s name: " << endl;
	cin >> name;

	cout << "Enter " << typeStr <<"'s description: " << endl;
	cin >> description;

	cout << "Enter " << typeStr <<"'s level: " << endl;
	cin >> level;

	if(type == 0)
		GodmodeActiveController::instance()->newFighter(name, description, level);
	else if(type == 1)
		GodmodeActiveController::instance()->newHostileNpc(name, description, level);
}

void GodmodeActiveView::postCreationView() {
	char input;

	ViewHelper::printDelimiter();

	cout << "Do you want to customize your " << typeStr << "'s stats or equip item(s) [Y/n]? " << endl;
	cin >> input;

	GodmodeActiveController::instance()->postCreation(ViewHelper::readBooleanInput(input));

}

void GodmodeActiveView::postCreationYesView() {
	int input;

	ViewHelper::printDelimiter();

	cout << "Please select and option" << endl;
	cout << "1. Change starting ability score" << endl
		<< "2. Equip item" << endl
		<< "3. Save and Quit" << endl
		<< "Selection: ";

	cin >> input;

	if (ViewHelper::isInputInValidRange(input, 1, 3))
		GodmodeActiveController::instance()->postCreationYes(input);
}

void GodmodeActiveView::changeAbilityScoreView() {
	int abilityScore[6];

	ViewHelper::printDelimiter();

	cout << "To modify ability score enter the ability score in the following format: str,dex,cons,int,wis,cha" << endl;
	cout << "To leave the ability score unchanged enter a -1 at the index of the ability score" << endl;
	cout << "Example: 9,-1,-1,-1,-1,-1 will only change the STRENGTH ability score" << endl;

	cin >> abilityScore[0] >> abilityScore[1] >> abilityScore[2] >> abilityScore[3] >> abilityScore[4] >> abilityScore[5];

	GodmodeActiveController::instance()->modifyAbilityScore(abilityScore);
}

void GodmodeActiveView::equipItemView() {
	char input;
	bool cont = true;

	while (cont) {
		char item;
		cout << "Choose an item to equip : (h: helmet, a: armor, s: shield, r: ring, b: belt, j: boots, w: weapon" << endl;
		cin >> item;

		GodmodeActiveController::instance()->equipItem(item);

		cout << "Do you want to continue to equip item? ([Y/n])" << endl;
		cin >> input;

		cont = ViewHelper::readBooleanInput(input);
	}
	postCreationYesView();
}

void GodmodeActiveView::validateFighterView(bool isValidFighter) {

	if (isValidFighter) {
		cout << typeStr << "'s ability score successfully modified!" << endl;
		postCreationYesView();
	}
	else {
		cout << "Failed to modify characters ability score!" << endl;
		changeAbilityScoreView();
	}
}

void GodmodeActiveView::saveAndQuitView(Active* fighter) {
	cout << typeStr << " successfully created" << endl;
	fighter->print();
	fighter->printEquipments();
	GodmodeActiveController::instance()->saveAndQuit();
}