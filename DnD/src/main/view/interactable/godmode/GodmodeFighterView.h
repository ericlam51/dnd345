#pragma once

#include "../../../helper/ViewHelper.h"
#include "../../../controller/interactable/godmode/GodmodeFighterController.h"
#include "../../../model/interactable/header/Fighter.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeFighterView {
public:
	static void newfighterView();
	static void postCreationView();
	static void postCreationYesView();
	static void equipItemView();
	static void changeAbilityScoreView();
	static void validateFighterView(bool isValidFighter);
	static void saveAndQuitView(Fighter* fighter);
};