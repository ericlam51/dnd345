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
	static void mapFileSelectionView();
	static void mapCreationParamSelectionView();
	static void mapOptionsView();
	static void mapElementSelectionView();
	static void mapDetailsView();
	static void invalidInputView();

	/* Warning messages */
	static void warningMsgChangingEntranceCell();
	static void warningMsgChangingExitCell();
};