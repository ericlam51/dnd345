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
	static void loadChestView();
	static void postCreationView();
	static void warningMsgChestLoaded();
	static void saveAndQuitView(Chest* chest);
};
