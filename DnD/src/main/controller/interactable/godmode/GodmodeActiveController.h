/*! GodmodeActiveController class
* Active controller used to load, create and edit hostile npc and fighter
*/
#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../model/interactable/header/Fighter.h"
#include "../../../model/item/Armor.h"
#include "../../../model/item/Boots.h"
#include "../../../model/item/Helmet.h"
#include "../../../model/item/Ring.h"
#include "../../../model/item/Weapon.h"
#include "../../../model/item/Shield.h"
#include "../../../controller/item/godmode/GodmodeItemController.h"
#include "../../../helper/FileHelper.h"

//#include "../../../model/item/Belt.h" //TODO

//! class for the implementation of load/edit active controller
//! this controller will handle the interaction between user and the software
class GodmodeActiveController {
	static GodmodeActiveController *s_instance;

private:
	// variable for the singleton 
	Active* _active = NULL;
	vector<string> filenames;

public:
	//! method to create or get the singleton class
	static GodmodeActiveController* instance();
	//method to create a fighter
	void newFighter(string name, string description, int level);
	//method to create a monster
	void newHostileNpc(string name, string description, int level);
	//method to load a fighter with the view to edit
	void loadFighter(int input);
	//method to load a fighter with the view to edit
	void loadHostileNpc(int input);
	//method to load a fighter without the view to edit
	void loadFighterWithoutView(int input);
	//method to load a monster without the view to edit
	void loadHostileNpcWithoutView(int input);
	//method to return a fighter  or monster created/loaded
	Active* getActive();
	//method to show view to edit fighter/monsters
	void postCreation(bool input);
	//method to show view to decide what to edit fighter/monsters
	void postCreationYes(int input);
	//method to show view to edit fighter/monsters ability score
	void modifyAbilityScore(int abilityScore[6]);
	//method to show to equip item on fighter/monsters
	void equipItem(char item);
	//Validate character before save
	void validateSaveRequirements();
	//method to show to save and quit fighter/monsters edit
	void saveAndQuit(string filename);
	//method to reset controller
	void resetGodmodeActiveController();
	//method to load active
	void getSavedActiveFiles(int type);

}; 
