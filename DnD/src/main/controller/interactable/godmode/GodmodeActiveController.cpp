#include "GodmodeActiveController.h"

void GodmodeActiveController::newFighter(string name, string description, int level) {
	_active = new Fighter(name, description, level);
	_active->print();
	GodmodeActiveView::postCreationView();
}

void GodmodeActiveController::newHostileNpc(string name, string description, int level){
	_active = new HostileNpc(name, description, level);
	_active->print();
	GodmodeActiveView::postCreationView();
}

void GodmodeActiveController::postCreation(bool input) {
	if (input)
		GodmodeActiveView::postCreationYesView();
	else
		GodmodeActiveView::saveAndQuitView(_active);  //TODO postCReationNo
}

void GodmodeActiveController::postCreationYes(int input) {
	switch (input) {
	case 1:
		GodmodeActiveView::changeAbilityScoreView();
		break;
	case 2:
		GodmodeActiveView::equipItemView();
		break;
	case 3:
		GodmodeActiveView::saveAndQuitView(_active);
			break;
	default:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	}
}

void GodmodeActiveController::modifyAbilityScore(int abilityScore[6]) {
	if(abilityScore[0] != -1)
		_active->setStrength(abilityScore[0]);

	if (abilityScore[1] != -1)
		_active->setDexterity(abilityScore[1]);

	if (abilityScore[2] != -1)
		_active->setConstitution(abilityScore[2]);

	if (abilityScore[3] != -1)
		_active->setIntelligence(abilityScore[3]);

	if (abilityScore[4] != -1)
		_active->setWisdom(abilityScore[4]);

	if (abilityScore[5] != -1)
		_active->setCharisma(abilityScore[5]);

	GodmodeActiveView::validateFighterView(_active->validateNewPlayer());
}

void GodmodeActiveController::equipItem(char item) {
	if (_active->equipItem(item))
		cout << item << " successfully equipped" << endl;
	else
		cout << item << "failed to equipped" << endl;
}

void GodmodeActiveController::saveAndQuit(){
	CFile theFile;

	if(strcmp(_active->GetRuntimeClass()->m_lpszClassName, "Fighter"))
		theFile.Open(_T("Fighter"), CFile::modeCreate | CFile::modeWrite);
	else if (strcmp(_active->GetRuntimeClass()->m_lpszClassName, "HostileNpc"))
		theFile.Open(_T("HostileNpc"), CFile::modeCreate | CFile::modeWrite);

	CArchive archive(&theFile, CArchive::store);
	_active->Serialize(archive);
	archive.Close();
	theFile.Close();

	delete _active;
	_active = NULL;
	GodmodeInteractableView::interactableFileSelectionView();
}

GodmodeActiveController* GodmodeActiveController::instance() {
	if (!s_instance)
		s_instance = new GodmodeActiveController();

	return s_instance;
}

GodmodeActiveController* GodmodeActiveController::s_instance = GodmodeActiveController::instance();