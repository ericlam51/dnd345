#pragma once

#include <iostream>
#include <ctime>
#include <math.h>
#include <string>
#include "view\GameModeView.h"
#include "helper\FileHelper.h"

#include "model\interactable\header\Active.h"
#include "controller\combat\CombatController.h"

using namespace std;

int main(){

	srand((unsigned)time(NULL));
	GameModeView gmv;
	gmv.displayView();
	//To start a Combat:
	//Active* fighter = new Fighter("Taleb", "someone", 5);
	//Active* monster = new HostileNpc("Roberto", "unpolite guy", 5);
	//CombatController cc;
	//cc.beginCombat(fighter, monster);

}
