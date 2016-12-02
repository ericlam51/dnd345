/*! GodmodeChestView class
* The V in MVC to show options to load/create chest
*/
#pragma once

#include "../../../controller/interactable/godmode/GodmodeChestController.h"
#include "../../../model/interactable/header/Chest.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeChestView {
public:
	static void newChestView();
	static void postCreationView();
	static void chestChooseSaveFileView(vector<string> filenames);
	static void chestAskSaveFileName();
	static void addItemToChestView();

	static void warningMsgInvalidInput();
	static void warningMsgChestLoaded();
	static void warningMsgChestSaved();

private:
	static bool readBooleanInput(char input);
};
