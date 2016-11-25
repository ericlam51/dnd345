#include "GodmodeChestController.h"

//! method Create new chest
void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
	GodmodeChestView::postCreationView();
}

//! method to load chest
void GodmodeChestController::loadChest() {
	loadChestWithoutView();

	GodmodeChestView::warningMsgChestLoaded();
	GodmodeChestView::postCreationView();
}

//! method to load chest without edit view
void GodmodeChestController::loadChestWithoutView() {
	CFile theFile;
	theFile.Open(_T("Chest"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_chest = new Chest();
	_chest->Serialize(archive);

	archive.Close();
	theFile.Close();
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
			GodmodeChestView::saveAndQuitView(_chest);
			break;
		default:
			GodmodeChestView::postCreationView();
			break;
	}
}

//! method to save and quit
void GodmodeChestController::saveAndQuit(){
	CFile theFile;
	theFile.Open(_T("Chest"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);
	_chest->Serialize(archive);
	archive.Close();
	theFile.Close(); 

	resetGodmodeChestController();

	GodmodeInteractableView::interactableFileSelectionView();
}

void GodmodeChestController::resetGodmodeChestController() {
	delete _chest;
	_chest = NULL;
}
GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();