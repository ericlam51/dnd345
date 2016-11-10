/*! GodmodeChestController class
* Chest controller used to load, create and edit chest
*/
#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../view/interactable/godmode/GodmodeActiveView.h"
#include  "../../../model/interactable/header/Chest.h"

class GodmodeChestController {
	static GodmodeChestController *s_instance;

private:
	Chest* _chest;
public:
	static GodmodeChestController* instance();
	void newChest(string name, string description);
	void loadChest();
	void loadChestWithoutView();
	Chest* getChest();

	void postCreation(int input);
	void saveAndQuit();
};