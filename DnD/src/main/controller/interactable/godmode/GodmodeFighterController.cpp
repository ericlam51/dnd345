#include "GodmodeFighterController.h"

void GodmodeFighterController::newFighter(string name, string description, int level) {
	_fighter = new Fighter(name, description, level);
	_fighter->print();
	GodmodeFighterView::postCreationView();
}

void GodmodeFighterController::postCreation(bool input) {
	if (input)
		GodmodeFighterView::postCreationYesView();
	else
		GodmodeInteractableView::interactableElementSelectionView();  //TODO postCReationNo
}

void GodmodeFighterController::postCreationYes(int input) {
	switch (input) {
	case 1:
		GodmodeFighterView::newfighterView();
		break;
	case 2:
		GodmodeFighterView::equipItemView();
		break;
	case 3: 
		GodmodeFighterView::saveAndQuitView(_fighter);
	default:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	}
}

void GodmodeFighterController::modifyAbilityScore(int abilityScore[6]) {
	if(abilityScore[0] != -1)
		_fighter->setStrength(abilityScore[0]);

	if (abilityScore[1] != -1)
		_fighter->setDexterity(abilityScore[1]);

	if (abilityScore[2] != -1)
		_fighter->setConstitution(abilityScore[2]);

	if (abilityScore[3] != -1)
		_fighter->setIntelligence(abilityScore[3]);

	if (abilityScore[4] != -1)
		_fighter->setWisdom(abilityScore[4]);

	if (abilityScore[5] != -1)
		_fighter->setCharisma(abilityScore[5]);

	GodmodeFighterView::validateFighterView(_fighter->validateNewPlayer());
}

void GodmodeFighterController::equipItem(char item) {
	if (_fighter->equipItem(item))
		cout << item << "successfully equipped" << endl;
	else
		cout << item << "failed to equipped" << endl;
}

GodmodeFighterController* GodmodeFighterController::instance() {
	if (!s_instance)
		s_instance = new GodmodeFighterController();

	return s_instance;
}

GodmodeFighterController* GodmodeFighterController::s_instance = GodmodeFighterController::instance();