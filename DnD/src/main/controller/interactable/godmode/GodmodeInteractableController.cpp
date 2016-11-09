#include "GodmodeInteractableController.h"

void GodmodeInteractableController::interactableFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	case 2:
		GodmodeInteractableView::interactableFileSelectionView();
	default:
		GodmodeInteractableView::interactableFileSelectionView();
		break;
	}
}

void GodmodeInteractableController::interactableCreation(int input) {
	switch (input) {
	case 1:
		GodmodeFighterView::newfighterView();
		break;
	case 2:
		GodmodeInteractableView::interactableFileSelectionView();
	case 3:
		GodmodeInteractableView::interactableFileSelectionView();
	case 4:
		GodmodeInteractableView::interactableFileSelectionView();
	default:
		GodmodeInteractableView::interactableFileSelectionView();
		break;
	}
}

void GodmodeInteractableController::fighterCreation(string name, string description, int level) {

}

GodmodeInteractableController* GodmodeInteractableController::instance() {
	if (!s_instance)
		s_instance = new GodmodeInteractableController();

	return s_instance;
}

GodmodeInteractableController* GodmodeInteractableController::s_instance = GodmodeInteractableController::instance();