/**
* Views for everything related to the Map in God mode. The view will then trigger the corresponding controller.
* Practically no logic is done here. Everything is routed to the controller, who takes of that.
*/

#pragma once

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
	static void fileOptionsMenuView(); /**< Shows the options to create a new file or load a new file */
	static void mapCreationInputView(); /**< Asks user to input the necessary parameters to create a new map. In this case, it will ask for a width and height */
	static void mapFillOptionsMenuView(); /**< Show the Cell types the user can set on the map. */
	static void mapOptionsMenuView(); /**< Shows the options to edit the map (ie: Fill a cell, validate the map, save the map */

	/* Warning messages. Consider them as notifications. */
	static void warningMsgChangingEntranceCell(); 
	static void warningMsgChangingExitCell();
	static void warningMsgInvalidInput();
	static void warningMsgInvalidMap();
	static void warningMsgValidMap();
	static void warningMsgMapSaved();
	static void warningMsgMapLoaded();
};