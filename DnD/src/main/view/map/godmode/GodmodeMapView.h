#pragma once

#include "../../../helper/ViewHelper.cpp"
#include "../../../controller/map/godmode/GodmodeMapController.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeMapView {
public:
	static void mapFileSelectionView();
	static void mapCreationParamSelectionView();
	static void mapElementSelectionView();
	static void mapDetailsView();
	static void invalidInputView();
};