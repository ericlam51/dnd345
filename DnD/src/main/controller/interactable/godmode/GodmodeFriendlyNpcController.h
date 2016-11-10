#pragma once

#include "../../../view/interactable/godmode/GodmodeFriendlyNpcView.h"
#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include  "../../../model/interactable/header/FriendlyNpc.h"

class GodmodeFriendlyNpcController {
	static GodmodeFriendlyNpcController *s_instance;

private:
	FriendlyNpc* _friendlyNpc;
public:
	void newFriendlyNpc(string name, string description, string dialog);
	void loadFriendlyNpc();
	void loadFriendlyNpcWithoutView();
	FriendlyNpc* getFriendlyNpc();
	void postCreation(int input);
	void saveAndQuit();
	static GodmodeFriendlyNpcController* instance();
};