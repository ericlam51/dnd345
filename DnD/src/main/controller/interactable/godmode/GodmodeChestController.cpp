#include "GodmodeChestController.h"

void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
	GodmodeChestView::postCreationView();
}

void GodmodeChestController::postCreation(int input){
	switch(input){
		case 1:
			GodmodeChestView::newChestView();
			break;
		case 2:
			GodmodeChestView::saveAndQuitView(_chest);
			break;
		default:
			GodmodeChestView::postCreationView();
			break;
	}
}

void GodmodeChestController::saveAndQuit(){
	//TODO serialize obj
	delete _chest;
	_chest = NULL;
}

GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();