#pragma once

class CombatView;
#include "../../helper/Logger.h"
#include "../../model/interactable/header/Active.h"
#include "../../view/combat/CombatView.h"
#include "../../model/dice/Dice.h"


class CombatController{
	static CombatView cv;
	// variable for the singleton 
	static CombatController * s_instance;
public:
	static CombatController* instance();
	static void beginCombat(Active* , Active*);
	static void fighterTurn();
	static void enemyTurn();
private:
	static Active* fighter;
	static Active* enemy;
	static void exitCombat();

};

