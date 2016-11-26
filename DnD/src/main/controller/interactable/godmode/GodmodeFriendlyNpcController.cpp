#include "GodmodeFriendlyNpcController.h"

//! method to create NPC
void GodmodeFriendlyNpcController::newFriendlyNpc(string name, string description, string dialog) {
	_friendlyNpc = new FriendlyNpc(name, description, dialog);
	GodmodeFriendlyNpcView::postCreationView();
}

//! method to load NPC
void GodmodeFriendlyNpcController::loadFriendlyNpc(int input) {
	loadFriendlyNpcWithoutView(input);
	print();
	GodmodeFriendlyNpcView::warningMsgFriendlyLoaded();
	GodmodeFriendlyNpcView::postCreationView();
}

//! method to load NPC with post creation view
void GodmodeFriendlyNpcController::loadFriendlyNpcWithoutView(int input) {
	if (input < 0 || input >= filenames.size()) {
		GodmodeFriendlyNpcView::friendlyChooseSaveFileView(filenames);
	}
	else {
		CFile theFile;
		string filePath = FileHelper::getDirectoryPath(FileHelper::FRIENDLY_FILE_FOLDER) + filenames[input];
		theFile.Open(_T(filePath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		_friendlyNpc = new FriendlyNpc();
		_friendlyNpc->Serialize(archive);

		archive.Close();
		theFile.Close();
	}
}

//! method to return NPC
FriendlyNpc* GodmodeFriendlyNpcController::getFriendlyNpc() {
	return _friendlyNpc;
}

//! method to create new npc or save and quit
void GodmodeFriendlyNpcController::postCreation(int input) {
	switch(input){
		case 1:
			GodmodeFriendlyNpcView::newFriendlyNpcView();
			break;
		case 2:
			GodmodeFriendlyNpcView::friendlyAskSaveFileName();
			break;
		default:
			GodmodeFriendlyNpcView::postCreationView();
			break;
	}
}

//! method to save and quit
void GodmodeFriendlyNpcController::saveAndQuit(string filename){
	CFile theFile;
	string fileDirectory = FileHelper::getDirectoryPath(FileHelper::FRIENDLY_FILE_FOLDER) + filename;
	theFile.Open(_T(fileDirectory.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_friendlyNpc->Serialize(archive);

	archive.Close();
	theFile.Close();

	print();
	resetGodmodeFriendlyNpcController();

	GodmodeFriendlyNpcView::warningMsgFriendlySaved();
	GodmodeInteractableView::interactableFileSelectionView();
}

void GodmodeFriendlyNpcController::getSavedFiles() {
	filenames = FileHelper::getFilenamesInDirectory(FileHelper::FRIENDLY_FILE_FOLDER);

	GodmodeFriendlyNpcView::friendlyChooseSaveFileView(filenames);
}

void GodmodeFriendlyNpcController::print() {
	_friendlyNpc->print();
}

void GodmodeFriendlyNpcController::resetGodmodeFriendlyNpcController() {
	delete _friendlyNpc;
	_friendlyNpc = NULL;

	filenames.clear();
	vector<string>().swap(filenames);
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::instance() {
	if (!s_instance)
		s_instance = new GodmodeFriendlyNpcController();

	return s_instance;
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::s_instance = GodmodeFriendlyNpcController::instance();