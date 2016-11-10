#include "GodmodeChestController.h"

void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
	GodmodeChestView::postCreationView();
}

void GodmodeChestController::loadChest() {
	loadChestWithoutView();

	GodmodeChestView::warningMsgChestLoaded();
	GodmodeChestView::postCreationView();
}

void GodmodeChestController::loadChestWithoutView() {
	CFile theFile;
	theFile.Open(_T("Chest"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_chest = new Chest();
	_chest->Serialize(archive);

	archive.Close();
	theFile.Close();
}

Chest* GodmodeChestController::getChest() {
	return _chest;
}

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

void GodmodeChestController::saveAndQuit(){
	CFile theFile;
	theFile.Open(_T("Chest"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);
	_chest->Serialize(archive);
	archive.Close();
	theFile.Close(); 

	delete _chest;
	_chest = NULL;

	GodmodeInteractableView::interactableFileSelectionView();
}

GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();