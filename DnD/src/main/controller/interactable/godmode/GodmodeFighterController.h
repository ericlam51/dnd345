#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../model/interactable/header/Fighter.h"

class GodmodeFighterController {
	static GodmodeFighterController *s_instance;

private:
	Fighter* _fighter;

public:
	static GodmodeFighterController* instance();
	void newFighter(string name, string description, int level);
}; 
