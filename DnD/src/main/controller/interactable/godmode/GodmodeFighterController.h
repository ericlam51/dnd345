#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../model/interactable/header/Fighter.h"

class GodmodeFighterController {
	static GodmodeFighterController *s_instance;

private:
	Fighter* _fighter;

public:
	static GodmodeFighterController* instance();
	void newFighter(string name, string description, int level);
	void postCreation(bool input);
	void postCreationYes(int input);
	void modifyAbilityScore(int abilityScore[6]);
	void equipItem(char item);

}; 
