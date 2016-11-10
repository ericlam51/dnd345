/*! GodmodeHostileNpcController class
* Hostile NPC controller used to load, create and edit interactables
* (Fighter, Monster, Npc, Chest)
*/
#pragma once

#include "../../../view/interactable/godmode/GodmodeInteractableView.h"
#include "../../../view/interactable/godmode/GodmodeActiveView.h"
#include  "../../../model/interactable/header/HostileNpc.h"

class GodmodeHostileNpcController {
	static GodmodeHostileNpcController *s_instance;

private:
	HostileNpc* _hostileNpc;
public:
	static GodmodeHostileNpcController* instance();
	void newHostileNpc(string name, string description, int level);
};