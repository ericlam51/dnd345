#pragma once

#include "../../../helper/ViewHelper.h"
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
	static void saveAndQuitView(Chest* chest);
};
