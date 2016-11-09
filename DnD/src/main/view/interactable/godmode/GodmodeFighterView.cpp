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

void GodmodeFighterView::postCreationView() {
	char input;

	ViewHelper::printDelimiter();

	cout << "Do you want to customize your character's stats or equip item(s) [Y/n]? " << endl;
	cin >> input;

	GodmodeFighterController::instance()->postCreation(ViewHelper::readBooleanInput(input));

}

void GodmodeFighterView::postCreationYesView() {
	int input;

	ViewHelper::printDelimiter();

	cout << "Please select and option" << endl;
	cout << "1. Change starting ability score" << endl
		<< "2. Equip item" << endl
		<< "3. Save and Quit" << endl
		<< "Selection: ";

	cin >> input;

	if (ViewHelper::isInputInValidRange(input, 1, 2))
		GodmodeFighterController::instance()->postCreationYes(input);
}

void GodmodeFighterView::changeAbilityScoreView() {
	int abilityScore[6];

	ViewHelper::printDelimiter();

	cout << "To modify ability score enter the ability score in the following format: str,dex,cons,int,wis,cha" << endl;
	cout << "To leave the ability score unchanged enter a -1 at the index of the ability score" << endl;
	cout << "Example: 9,-1,-1,-1,-1,-1 will only change the STRENGTH ability score";

	cin >> abilityScore[0] >> abilityScore[1] >> abilityScore[2] >> abilityScore[3] >> abilityScore[4] >> abilityScore[5];

	GodmodeFighterController::instance()->modifyAbilityScore(abilityScore);
}

void GodmodeFighterView::equipItemView() {
	char input;
	bool cont = true;

	while (cont) {
		char item;
		cout << "Choose an item to equip : (h: helmet, a: armor, s: shield, r: ring, b: belt, j: boots, w: weapon" << endl;
		cin >> item;

		GodmodeFighterController::instance()->equipItem(item);

		cout << "Do you want to continue to equip item? ([Y/n])" << endl;
		cin >> input;

		cont = ViewHelper::readBooleanInput(input);
	}
	postCreationYesView();
}

void GodmodeFighterView::validateFighterView(bool isValidFighter) {

	if (isValidFighter) {
		cout << "Character's ability score successfully modified!" << endl;
		postCreationYesView();
	}
	else {
		cout << "Failed to modify characters ability score!" << endl;
		changeAbilityScoreView();
	}
}

void GodmodeFighterView::saveAndQuitView(Fighter* fighter) {
	cout << "Fighter successfully created" << endl;
	cout << fighter;
	fighter->printEquipments();
	GodmodeInteractableView::interactableFileSelectionView();
}