#include "GodmodeChestView.h"
#undef max

//! method to create chest
void GodmodeChestView::newChestView() {

	string name, description;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Enter chest's name: " << endl;
	cin.ignore();
	getline(cin, name);
	

	cout << "Enter chest's description: " << endl;
	getline(cin, description);

	GodmodeChestController::instance()->newChest(name, description);
}

//! method to create chest another chest or save and quit
void GodmodeChestView::postCreationView(){
	int input = 0;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Please select an option" << endl;
	cout << "1. Create another Chest" << endl
		<< "2. Save and Quit" << endl;
		 
	do {
		cout << "Selection: " << endl;
		cin.clear();
		cin >> input;
	} while (input < 1 || input > 2);

	GodmodeChestController::instance()->postCreation(input);
}

void GodmodeChestView::chestChooseSaveFileView(vector<string> filenames) {
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

	GodmodeChestController::instance()->loadChest(input - 1);
}

void GodmodeChestView::chestAskSaveFileName() {
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeChestController::instance()->saveAndQuit(filename);
}

void GodmodeChestView::addItemToChestView() {

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

			GodmodeChestController::instance()->addItem(item);

			cout << "Do you want to continue to add item? ([Y/n])" << endl;
			cin >> input;

			cont = readBooleanInput(input);
		}

		GodmodeChestView::postCreationView();
	}
	else
	{
		cout << "There are currently no inventories, please create and save one to equip an item." << endl;
	}
	//postCreationYesView();
}

bool GodmodeChestView::readBooleanInput(char input) {
	if (input == 'y' || input == 'Y')
		return true;

	if (input == 'n' || input == 'N')
		return false;

	return false;

}

//! method show success creation message
void GodmodeChestView::warningMsgInvalidInput() {
	cout << "Invalid input" << endl;
}

//! method show success creation message
void GodmodeChestView::warningMsgChestLoaded() {
	cout << "Chest loaded" << endl;
}

//! method show success creation message
void GodmodeChestView::warningMsgChestSaved() {
	cout << "Chest saved" << endl;
}