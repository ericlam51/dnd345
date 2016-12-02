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
	Chest* _chest = NULL;
	vector<string> filenames;
	int option = 0;

public:
	static GodmodeChestController* instance();
	void newChest(string name, string description);
	void loadChest(int input);
	void loadChestWithoutView(int input);
	Chest* getChest();
	void addItem(char item);

	void postCreation(int input);
	void saveAndQuit(string filename);
	void getSavedFiles(int option = 0);
	void resetGodmodeChestController();
	void print();
};