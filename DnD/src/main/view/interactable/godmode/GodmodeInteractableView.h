#pragma once

#include "../../../controller/interactable/godmode/GodmodeInteractableController.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class GodmodeInteractableView {
public:
	static void interactableFileSelectionView();
	static void interactableElementSelectionView();
	static void interactableLoadView();
};