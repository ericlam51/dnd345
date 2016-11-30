/*! GodmodeFriendlyNpcController class
* NPC controller used to load, create and edit friendly npc
*/
#pragma once

#include "../../../view/interactable/godmode/GodmodeFriendlyNpcView.h"
#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include  "../../../model/interactable/header/FriendlyNpc.h"

class GodmodeFriendlyNpcController {
	static GodmodeFriendlyNpcController *s_instance;

private:
	FriendlyNpc* _friendlyNpc;
	vector<string> filenames;
	int option = 0;

public:
	void newFriendlyNpc(string name, string description, string dialog);
	void loadFriendlyNpc(int input);
	void loadFriendlyNpcWithoutView(int input);
	FriendlyNpc* getFriendlyNpc();
	void postCreation(int input);
	void saveAndQuit(string filename);
	void getSavedFiles(int option = 0);
	void resetGodmodeFriendlyNpcController();
	void print();
	static GodmodeFriendlyNpcController* instance();
};