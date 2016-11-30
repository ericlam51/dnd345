#pragma once

class CombatController;

#include "../../model/interactable/header/Active.h"
#include "../../controller/combat/CombatController.h"


class CombatView
{
	static CombatController cc;
	// variable for the singleton 
	static CombatView * s_instance;
public:
	static CombatView* instance();
	static void printCombat(Active*, Active*, bool);

};

