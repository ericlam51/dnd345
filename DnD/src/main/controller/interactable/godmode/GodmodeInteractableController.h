#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../view/interactable/godmode/GodmodeActiveView.h"
#include "../../../view/interactable/godmode/GodmodeHostileNpcView.h"
#include "../../../view/interactable/godmode/GodmodeFriendlyNpcView.h"
#include "../../../view/interactable/godmode/GodmodeChestView.h"

class GodmodeInteractableController {
	static GodmodeInteractableController *s_instance;

private:

public:
	static GodmodeInteractableController* instance();
	void interactableFileSelection(int input);
	void interactableLoad(int input);
	void interactableCreation(int input);
};