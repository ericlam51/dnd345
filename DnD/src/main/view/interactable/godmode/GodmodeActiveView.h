/*! GodmodeActiveView class
* The V in MVC to show options to load/create hostile and fighter
*/
#pragma once

#include "../../../controller/interactable/godmode/GodmodeActiveController.h"
#include "../../../model/interactable/header/Fighter.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeActiveView {
public:
	static void newActiveView(int type);
	static void postCreationView();
	static void postCreationYesView();
	static void equipItemView();
	static void changeAbilityScoreView();
	static void validateFighterView(bool isValidFighter);
	static void activeChooseSaveFileView(vector<string> filenames, int type);
	static void activeAskSaveFileName();
	static void warningMsgActiveLoaded();
	static void warningMsgInvalidInput(); 
	static void warningInvalidCharacter();

private:
	static string typeStr;
};