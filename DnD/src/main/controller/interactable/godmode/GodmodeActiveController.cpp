#include "GodmodeActiveController.h"

//! method to create a fighter
//!@param name: Name of fighter
//!@param description: Description of fighter
//!@param level: Level of fighter
void GodmodeActiveController::newFighter(string name, string description, int level) {
	_active = new Fighter(name, description, level);
	_active->print();
	GodmodeActiveView::postCreationView();
}

//! method to create a monster
//! method to create a monster
//!@param name: Name of monster
//!@param description: Description of monster
//!@param level: Level of monster
void GodmodeActiveController::newHostileNpc(string name, string description, int level){
	_active = new HostileNpc(name, description, level);
	_active->print();
	GodmodeActiveView::postCreationView();
}

//!method to load a fighter with the view to edit
void GodmodeActiveController::loadFighter(int input){
	loadFighterWithoutView(input);
	_active->print();
	GodmodeActiveView::warningMsgActiveLoaded();
	GodmodeActiveView::postCreationView();
}
//! method to load a fighter with the view to edit
void GodmodeActiveController::loadHostileNpc(int input){
	loadHostileNpcWithoutView(input);
	_active->print();
	GodmodeActiveView::warningMsgActiveLoaded();
	GodmodeActiveView::postCreationView();
}
//! method to load a fighter without the view to edit
void GodmodeActiveController::loadFighterWithoutView(int input) {
	if (input < 0 || input >= filenames.size()) {
		GodmodeActiveView::activeChooseSaveFileView(filenames); //TODO
	}
	else {
		CFile theFile;
		string filePath = FileHelper::getDirectoryPath(FileHelper::FIGHTER_FILE_FOLDER) + filenames[input];
		theFile.Open(_T(filePath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		_active = new Fighter();
		_active->Serialize(archive);

		archive.Close();
		theFile.Close();
	}
}

//! method to load a monster without the view to edit
void GodmodeActiveController::loadHostileNpcWithoutView(int input) {
	if (input < 0 || input >= filenames.size()) {
		GodmodeActiveView::activeChooseSaveFileView(filenames);
	}
	else {
		CFile theFile;
		string filePath = FileHelper::getDirectoryPath(FileHelper::HOSTILE_FILE_FOLDER) + filenames[input];
		theFile.Open(_T(filePath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		_active = new HostileNpc();
		_active->Serialize(archive);

		archive.Close();
		theFile.Close();
	}
}

//! method to return a fighter  or monster created/loaded
Active* GodmodeActiveController::getActive() {
	return _active;
}

//! method to show view to edit fighter/monsters
//!@param input: Either yes or No to edit fighter/monster
void GodmodeActiveController::postCreation(bool input) {
	if (input)
		GodmodeActiveView::postCreationYesView();
	else
		GodmodeActiveController::instance()->validateSaveRequirements();
}

//! method to show view to decide what to edit fighter/monsters
//!@param input: Yes view to edit fighter/monster
void GodmodeActiveController::postCreationYes(int input) {
	switch (input) {
	case 1:
		GodmodeActiveView::changeAbilityScoreView();
		break;
	case 2:
		GodmodeActiveView::equipItemView();
		break;
	case 3:
		GodmodeActiveController::instance()->validateSaveRequirements();
		break;
	default:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	}
}

//! method to show view to edit fighter/monsters ability score
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

//! method to show to equip item on fighter/monsters
//! @param item: item to equip
void GodmodeActiveController::equipItem(char item) {
	GodmodeItemController::instance()->loadSaveFile();

	switch (item) {
		case 'h':
		{
			Item* helmet = GodmodeItemController::instance()->getContainer()->getItem("HELMET", 0);
			_active->equipItem(helmet);
			cout << "successfully equipped" << endl;
		}
		break;
		case 'a':
		{
			Item* armor = GodmodeItemController::instance()->getContainer()->getItem("ARMOR", 0);
			_active->equipItem(armor);
			cout << "successfully equipped" << endl;
		}
		break;
		case 's':
		{
			Item* shield = GodmodeItemController::instance()->getContainer()->getItem("SHIELD", 0);
			_active->equipItem(shield);
			cout << "successfully equipped" << endl;
		}
		break;
		case 'r':
		{
			Item* ring = GodmodeItemController::instance()->getContainer()->getItem("RING", 0);
			_active->equipItem(ring);
			cout << "successfully equipped" << endl;
		}
		break;
		//case 'b':
		//	Helmet* helmet;
		//	_active->equipItem(helmet);
		//	break;
		case 'j':
		{
			Item* boots = GodmodeItemController::instance()->getContainer()->getItem("BOOTS", 0);
			_active->equipItem(boots);
			cout << "successfully equipped" << endl;
		}
		break;
		case 'w':
		{
			Item* weapon = GodmodeItemController::instance()->getContainer()->getItem("WEAPON", 0);
			_active->equipItem(weapon);
			cout << "successfully equipped" << endl;
		}
		break;
		default:
			cout << "failed to equipped" << endl;
	}
}
void GodmodeActiveController::validateSaveRequirements() {
	bool valid = _active->validateNewPlayer();

	if (!valid) {
		GodmodeActiveView::warningInvalidCharacter();
		GodmodeActiveView::postCreationYesView();
		return;
	}

	GodmodeActiveView::activeAskSaveFileName();
}

//! method to show to save and quit fighter/monsters edit
void GodmodeActiveController::saveAndQuit(string filename){
	CFile theFile;
	string fileDirectory = "";

	if(strcmp(_active->GetRuntimeClass()->m_lpszClassName, "Fighter") == 0)
		fileDirectory = FileHelper::getDirectoryPath(FileHelper::FIGHTER_FILE_FOLDER) + filename;
	else if (strcmp(_active->GetRuntimeClass()->m_lpszClassName, "HostileNpc") == 0)
		fileDirectory = FileHelper::getDirectoryPath(FileHelper::HOSTILE_FILE_FOLDER) + filename;
		
	theFile.Open(_T(fileDirectory.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	_active->Serialize(archive);

	archive.Close();
	theFile.Close();

	cout << " successfully created" << endl;
	_active->print();
	_active->printEquipments();

	resetGodmodeActiveController();
	GodmodeInteractableView::interactableFileSelectionView();
}

void GodmodeActiveController::resetGodmodeActiveController() {
	delete _active;
	_active = NULL;

	filenames.clear();
	vector<string>().swap(filenames);
}

void GodmodeActiveController::getSavedActiveFiles(int type) {

	if (type == 0)
		filenames = FileHelper::getFilenamesInDirectory(FileHelper::FIGHTER_FILE_FOLDER);
	else if (type == 1)
		filenames = FileHelper::getFilenamesInDirectory(FileHelper::HOSTILE_FILE_FOLDER);

	GodmodeActiveView::activeChooseSaveFileView(filenames); 
}

//! method to create or get the singleton class
GodmodeActiveController* GodmodeActiveController::instance() {
	if (!s_instance)
		s_instance = new GodmodeActiveController();

	return s_instance;
}

GodmodeActiveController* GodmodeActiveController::s_instance = GodmodeActiveController::instance();