#include "GodmodeActiveView.h"
#undef max
string GodmodeActiveView::typeStr = "";

bool readBooleanInput(char input) {
	if (input == 'y' || input == 'Y')
		return true;

	if (input == 'n' || input == 'N')
		return false;

	return false;

}

//! method to create new monster or fighter
void GodmodeActiveView::newActiveView(int type) {

	string name, description;
	int level;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	if(type == 0)
		typeStr = "Fighter";
	else if (type == 1)
		typeStr = "Monster";

	cout << "Enter " << typeStr <<"'s name: " << endl;
	cin.ignore();
	getline(cin, name);

	cout << "Enter " << typeStr <<"'s description: " << endl;
	getline(cin, description);

	cout << "Enter " << typeStr <<"'s level: " << endl;
	cin >> level;

	if(type == 0)
		GodmodeActiveController::instance()->newFighter(name, description, level);
	else if(type == 1)
		GodmodeActiveController::instance()->newHostileNpc(name, description, level);
}

//! method to prompt edit monster or fighter
void GodmodeActiveView::postCreationView() {
	char input;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Do you want to customize your " << typeStr << "'s stats or equip item(s) [Y/n]? " << endl;
	cin >> input;

	GodmodeActiveController::instance()->postCreation(readBooleanInput(input));

}

//! method to edit monster or fighter if the user wants to edit
void GodmodeActiveView::postCreationYesView() {
	int input;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Please select and option" << endl;
	cout << "1. Change starting ability score" << endl
		<< "2. Equip item" << endl
		<< "3. Save and Quit" << endl;

	do {
		cout << "Selection: " << endl;
		cin.clear();
		cin >> input;
	} while (input < 1 || input > 3);
	
	GodmodeActiveController::instance()->postCreationYes(input);
}

//! method to edit monster or fighter ability score
void GodmodeActiveView::changeAbilityScoreView() {
	int abilityScore[6];

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "To modify ability score enter the ability score in the following format: str,dex,cons,int,wis,cha" << endl;
	cout << "To leave the ability score unchanged enter a -1 at the index of the ability score" << endl;
	cout << "Example: 9,-1,-1,-1,-1,-1 will only change the STRENGTH ability score" << endl;

	cin >> abilityScore[0] >> abilityScore[1] >> abilityScore[2] >> abilityScore[3] >> abilityScore[4] >> abilityScore[5];

	GodmodeActiveController::instance()->modifyAbilityScore(abilityScore);
}

//! method to equip item on monster or fighter
void GodmodeActiveView::equipItemView() {

	GodmodeItemController::instance()->resetController();
	system("cls");
	cout << "Please begin by selecting an inventory to load." << endl;
	vector<string> files = FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER);
	if (files.size() > 0)
	{
		GodmodeItemView::loadItemInventoryHelper(FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER));

		char input;
		bool cont = true;
		while (cont) {
			char item;
			cout << "Choose an item to equip : (h: helmet, a: armor, s: shield, r: ring, j: boots, w: weapon" << endl;
			cin >> item;

			GodmodeActiveController::instance()->equipItem(item);

			cout << "Do you want to continue to equip item? ([Y/n])" << endl;
			cin >> input;

			cont = readBooleanInput(input);
		}

	}
	else
	{
		cout << "There are currently no inventories, please create and save one to equip an item." << endl;
	}
	postCreationYesView();
}

//! method to validate monster or fighter
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

void GodmodeActiveView::warningMsgActiveLoaded() {
	cout << typeStr <<" loaded" << endl;
}

void GodmodeActiveView::activeChooseSaveFileView(vector<string> filenames, int type) {
	if (filenames.size() == 0) {
		cout << "No files created. Please create some first" << endl;
		return;
	}

	cout << "Please select one of the following files:" << endl;
	int input = 0;
	for (int i = 0; i < filenames.size(); i++) {
		cout << i + 1 << ". " << filenames[i] << endl;
	}

	do {
		cout << "Selection: " << endl;
		cin.clear();
		cin >> input;
	} while (input < 1 || input > filenames.size());

	if (type == 0 )
		GodmodeActiveController::instance()->loadFighter(input - 1);
	else if (type == 1)
		GodmodeActiveController::instance()->loadHostileNpc(input - 1);
}

void GodmodeActiveView::activeAskSaveFileName() {
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeActiveController::instance()->saveAndQuit(filename);
}

void GodmodeActiveView::warningMsgInvalidInput() {
	cout << "Invalid input!" << endl;
}

void GodmodeActiveView::warningInvalidCharacter() {
	cout << "Invalid character";
}