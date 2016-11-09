#pragma once

#include "../../../helper/ViewHelper.cpp"
#include "../../../controller/map/godmode/GodmodeMapController.h"
#include "../../../model/map/ChestCell.h"
#include "../../../model/map/EntranceCell.h"
#include "../../../model/map/ExitCell.h"
#include "../../../model/map/EntityCell.h"
#include "../../../model/map/PathCell.h"
#include "../../../model/map/WallCell.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeMapView {
public:
	/* Option menus */
	static void fileOptionsMenuView();
	static void mapCreationInputView();
	static void mapFillOptionsMenuView();
	static void mapOptionsMenuView();
	
	static void mapElementSelectionView();
	static void mapDetailsView();

	/* Warning messages */
	static void warningMsgChangingEntranceCell();
	static void warningMsgChangingExitCell();
	static void warningMsgInvalidInput();
	static void warningMsgInvalidMap();
	static void warningMsgValidMap();
};