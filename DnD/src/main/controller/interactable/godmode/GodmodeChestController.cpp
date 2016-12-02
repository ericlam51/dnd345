#include "GodmodeChestController.h"

//! method Create new chest
void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
	GodmodeChestView::addItemToChestView();
}

//! method to load chest
void GodmodeChestController::loadChest(int input) {
	loadChestWithoutView(input);

	if (option == 0) {
		print();
		GodmodeChestView::warningMsgChestLoaded();
		GodmodeChestView::postCreationView();
	}
}

//! method to load chest without edit view
void GodmodeChestController::loadChestWithoutView(int input) {
	if (input < 0 || input >= filenames.size()) {
		GodmodeChestView::chestChooseSaveFileView(filenames);
	}
	else {
		CFile theFile;
		string filePath = FileHelper::getDirectoryPath(FileHelper::CHEST_FILE_FOLDER) + filenames[input];
		theFile.Open(_T(filePath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		_chest = new Chest();
		_chest->Serialize(archive);

		archive.Close();
		theFile.Close();
	}
}

//! method to return chest object
Chest* GodmodeChestController::getChest() {
	return _chest;
}

//! method add another chest or save and quit
void GodmodeChestController::postCreation(int input){
	switch(input){
		case 1:
			GodmodeChestView::newChestView();
			break;
		case 2:
			GodmodeChestView::chestAskSaveFileName();
			break;
		default:
			GodmodeChestView::postCreationView();
			break;
	}
}

//! method to save and quit
void GodmodeChestController::saveAndQuit(string filename){

	CFile theFile;
	string fileDirectory = FileHelper::getDirectoryPath(FileHelper::CHEST_FILE_FOLDER) + filename;
	theFile.Open(_T(fileDirectory.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_chest->Serialize(archive);

	archive.Close();
	theFile.Close();

	print();
	resetGodmodeChestController();

	GodmodeChestView::warningMsgChestSaved();
	GodmodeInteractableView::interactableFileSelectionView();
}

void GodmodeChestController::getSavedFiles(int option) {
	this->option = option;
	filenames = FileHelper::getFilenamesInDirectory(FileHelper::CHEST_FILE_FOLDER);

	GodmodeChestView::chestChooseSaveFileView(filenames); 
}

void GodmodeChestController::resetGodmodeChestController() {
	delete _chest;
	_chest = NULL;

	filenames.clear();
	vector<string>().swap(filenames);

	option = 0;
}

void GodmodeChestController::print() {
	_chest->print();
}

void GodmodeChestController::addItem(char item) {
	switch (item) {
	case 'h':
	{
		Item* helmet = GodmodeItemController::instance()->getContainer()->getItem("HELMET", 0);
		if (helmet == nullptr)
		{
			cout << "There are currently no helmets created, you will need to create a helmet before you can add one." << endl;
		}
		else
		{
			_chest->addItem(helmet);
			cout << "Successfully added helmet." << endl;
		}
	}
	break;
	case 'a':
	{
		Item* armor = GodmodeItemController::instance()->getContainer()->getItem("ARMOR", 0);
		if (armor == nullptr)
		{
			cout << "There are currently no armors created, you will need to create an armor before you can add one." << endl;
		}
		else
		{
			_chest->addItem(armor);
			cout << "Successfully added armor." << endl;
		}
	}
	break;
	case 's':
	{
		Item* shield = GodmodeItemController::instance()->getContainer()->getItem("SHIELD", 0);
		if (shield == nullptr)
		{
			cout << "There are currently no shields created, you will need to create a shield before you can add one." << endl;
		}
		else
		{
			_chest->addItem(shield);
			cout << "Successfully added shield." << endl;
		}
	}
	break;
	case 'r':
	{
		Item* ring = GodmodeItemController::instance()->getContainer()->getItem("RING", 0);
		if (ring == nullptr)
		{
			cout << "There are currently no rings created, you will need to create a ring before you can add one." << endl;
		}
		else
		{
			_chest->addItem(ring);
			cout << "Successfully added ring." << endl;
		}
	}
	break;
	case 'j':
	{
		Item* boots = GodmodeItemController::instance()->getContainer()->getItem("BOOTS", 0);
		if (boots == nullptr)
		{
			cout << "There are currently no boots created, you will need to create boots before you can add one." << endl;
		}
		else
		{
			_chest->addItem(boots);
			cout << "Successfully added boots." << endl;
		}
	}
	break;
	case 'w':
	{
		Item* weapon = GodmodeItemController::instance()->getContainer()->getItem("WEAPON", 0);
		if (weapon == nullptr)
		{
			cout << "There are currently no weapons created, you will need to create a weapon before you can add one." << endl;
		}
		else
		{
			_chest->addItem(weapon);
			cout << "Successfully added weapon." << endl;
		}
	}
	break;
	default:
		cout << "Failed to add." << endl;
	}
}

GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();