#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../view/interactable/godmode/GodmodeFighterView.h"

class GodmodeInteractableController {
	static GodmodeInteractableController *s_instance;

private:

public:
	static GodmodeInteractableController* instance();
	void interactableFileSelection(int input);
	void interactableCreation(int input);
	void fighterCreation(string name, string description, int level);
};