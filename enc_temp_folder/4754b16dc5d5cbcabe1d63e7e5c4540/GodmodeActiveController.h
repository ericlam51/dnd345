#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../model/interactable/header/Fighter.h"

class GodmodeActiveController {
	static GodmodeActiveController *s_instance;

private:
	Active* _active;

public:
	static GodmodeActiveController* instance();
	void newFighter(string name, string description, int level);
	void newHostileNpc(string name, string description, int level);
	void loadFighter();
	void loadHostileNpc();
	void loadFighterWithoutView();
	void loadHostileNpcWithoutView();
	Active* getActive();
	void postCreation(bool input);
	void postCreationYes(int input);
	void modifyAbilityScore(int abilityScore[6]);
	void equipItem(char item);
	void saveAndQuit();

}; 
