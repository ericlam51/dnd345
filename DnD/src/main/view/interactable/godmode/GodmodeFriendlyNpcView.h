/*! GodmodeFriendlyNpcView class
* The V in MVC to show options to load/create friendly npc
*/

#pragma once

#include "../../../controller/interactable/godmode/GodmodeFriendlyNpcController.h"
#include "../../../model/interactable/header/FriendlyNpc.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeFriendlyNpcView {
public:
	static void newFriendlyNpcView();
	static void loadFriendlyNpcView();
	static void postCreationView();
	static void warningMsgFriendlyNpcLoaded();
	static void saveAndQuitView(FriendlyNpc* friendlyNpc);
};
