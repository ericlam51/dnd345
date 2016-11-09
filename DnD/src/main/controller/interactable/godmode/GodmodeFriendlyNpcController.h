#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../view/interactable/godmode/GodmodeFighterView.h"
#include  "../../../model/interactable/header/FriendlyNpc.h"

class GodmodeFriendlyNpcController {
	static GodmodeFriendlyNpcController *s_instance;

private:
	FriendlyNpc* _friendlyNpc;
public:
	static GodmodeFriendlyNpcController* instance();
	void newFriendlyNpc(string name, string description, int level);
};