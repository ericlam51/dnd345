#include "GodmodeChestController.h"

//! method Create new chest
void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
	GodmodeChestView::postCreationView();
}

//! method to load chest
void GodmodeChestController::loadChest(int input) {
	loadChestWithoutView(input);

	print();
	GodmodeChestView::warningMsgChestLoaded();
	GodmodeChestView::postCreationView();
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

void GodmodeChestController::getSavedFiles() {
	filenames = FileHelper::getFilenamesInDirectory(FileHelper::CHEST_FILE_FOLDER);

	GodmodeChestView::chestChooseSaveFileView(filenames); 
}

void GodmodeChestController::resetGodmodeChestController() {
	delete _chest;
	_chest = NULL;

	filenames.clear();
	vector<string>().swap(filenames);
}

void GodmodeChestController::print() {
	_chest->print();
}

GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();