#pragma once

#include "../../../helper/ViewHelper.h"
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
