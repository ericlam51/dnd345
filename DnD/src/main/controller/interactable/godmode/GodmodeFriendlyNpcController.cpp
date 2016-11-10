#include "GodmodeFriendlyNpcController.h"

void GodmodeFriendlyNpcController::newFriendlyNpc(string name, string description, string dialog) {
	_friendlyNpc = new FriendlyNpc(name, description, dialog);
	GodmodeFriendlyNpcView::postCreationView();
}

void GodmodeFriendlyNpcController::loadFriendlyNpc() {
	CFile theFile;
	theFile.Open(_T("FriendlyNpc"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_friendlyNpc = new FriendlyNpc();
	_friendlyNpc->Serialize(archive);

	archive.Close();
	theFile.Close();

	GodmodeFriendlyNpcView::warningMsgFriendlyNpcLoaded();
	GodmodeFriendlyNpcView::postCreationView();
}

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