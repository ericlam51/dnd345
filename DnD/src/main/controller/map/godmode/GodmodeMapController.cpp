#include "GodmodeMapController.h"

void GodmodeMapController::mapFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapCreationParamSelectionView();
		break;
	case 2:
		break; //TODO
	case 0:
		GodmodeMapView::invalidInputView();
		GodmodeMapView::mapFileSelectionView();
		break; 
	default: 
		GodmodeMapView::invalidInputView();
		GodmodeMapView::mapFileSelectionView();
		break;
	}
}

void GodmodeMapController::newMap(int width, int height) {
	if (width == 0 || height == 0) {
		GodmodeMapView::invalidInputView();
		GodmodeMapView::mapCreationParamSelectionView();
	}
	else {
		map = new Map();
	}
}

GodmodeMapController* GodmodeMapController::instance() {
	if (!s_instance)
		s_instance = new GodmodeMapController();

	return s_instance;
}

GodmodeMapController* GodmodeMapController::s_instance = GodmodeMapController::instance();