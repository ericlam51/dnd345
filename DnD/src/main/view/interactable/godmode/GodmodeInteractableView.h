#pragma once

#include "../../../helper/ViewHelper.h"
#include "../../../controller/interactable/godmode/GodmodeInteractableController.h"
#include "../../../model/interactable/header/ActiveBuilder.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeInteractableView {
public:
	static void interactableFileSelectionView();
	static void interactableElementSelectionView();
};