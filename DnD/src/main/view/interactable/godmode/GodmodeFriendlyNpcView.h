/*! GodmodeFriendlyNpcView class
* The V in MVC to show options to load/create friendly npc
*/

#pragma once

#include "../../../controller/interactable/godmode/GodmodeFriendlyNpcController.h"
#include "../../../model/interactable/header/FriendlyNpc.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GodmodeFriendlyNpcView {
public:
	static void newFriendlyNpcView();
	static void postCreationView();
	static void friendlyChooseSaveFileView(vector<string> filenames);
	static void friendlyAskSaveFileName();
	static void warningMsgInvalidInput();
	static void warningMsgFriendlySaved();
	static void warningMsgFriendlyLoaded();
};
