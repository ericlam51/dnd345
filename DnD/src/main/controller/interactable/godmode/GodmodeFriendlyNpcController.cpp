#include "GodmodeFriendlyNpcController.h"

//! method to create NPC
void GodmodeFriendlyNpcController::newFriendlyNpc(string name, string description, string dialog) {
	_friendlyNpc = new FriendlyNpc(name, description, dialog);
	GodmodeFriendlyNpcView::postCreationView();
}

//! method to load NPC
void GodmodeFriendlyNpcController::loadFriendlyNpc() {
	loadFriendlyNpcWithoutView();

	GodmodeFriendlyNpcView::warningMsgFriendlyNpcLoaded();
	GodmodeFriendlyNpcView::postCreationView();
}

//! method to load NPC with post creation view
void GodmodeFriendlyNpcController::loadFriendlyNpcWithoutView() {
	CFile theFile;
	theFile.Open(_T("FriendlyNpc"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_friendlyNpc = new FriendlyNpc();
	_friendlyNpc->Serialize(archive);

	archive.Close();
	theFile.Close();
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
			GodmodeFriendlyNpcView::saveAndQuitView(_friendlyNpc);
			break;
		default:
			GodmodeFriendlyNpcView::postCreationView();
			break;
	}
}

//! method to save and quit
void GodmodeFriendlyNpcController::saveAndQuit(){
	CFile theFile;
	theFile.Open(_T("FriendlyNpc"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);
	_friendlyNpc->Serialize(archive);
	archive.Close();
	theFile.Close();

	delete(_friendlyNpc);
	_friendlyNpc = NULL;
	GodmodeInteractableView::interactableFileSelectionView();
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::instance() {
	if (!s_instance)
		s_instance = new GodmodeFriendlyNpcController();

	return s_instance;
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::s_instance = GodmodeFriendlyNpcController::instance();