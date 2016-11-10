#pragma once

#include "../../../helper/ViewHelper.h"
#include "../../../controller/interactable/godmode/GodmodeActiveController.h"
#include "../../../model/interactable/header/Fighter.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeActiveView {
public:
	static void newActiveView(int type);
	static void loadActiveView(int type);
	static void postCreationView();
	static void postCreationYesView();
	static void equipItemView();
	static void changeAbilityScoreView();
	static void validateFighterView(bool isValidFighter);
	static void warningMsgActiveLoaded();
	static void saveAndQuitView(Active* fighter);

private:
	static string typeStr;
};