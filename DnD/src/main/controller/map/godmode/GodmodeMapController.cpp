#include "GodmodeMapController.h"

void GodmodeMapController::mapFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapCreationParamSelectionView();
		break;
	case 2:
		break; //TODO
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
		map = new Map(width, height);
		map->print();
	}
}

void GodmodeMapController::mapOptionsView(int x, int y, char charType) {
	switch (charType) {
	case CellHelper::WALL_TYPE:
		s_instance->setCell(x, y, new WallCell());
		break;
	case  CellHelper::ENTRANCE_TYPE:
		s_instance->setCell(x, y, new EntranceCell());
		break;
	case  CellHelper::EXIT_TYPE:
		s_instance->setCell(x, y, new ExitCell());
		break;
	case  CellHelper::CHEST_TYPE:
		s_instance->setCell(x, y, new ChestCell());
		break;
	case  CellHelper::ENTITY_TYPE:
		s_instance->setCell(x, y, new EntityCell());
		break;
	case  CellHelper::PATH_TYPE:
		s_instance->setCell(x, y, new PathCell());
		break;
	default:
		GodmodeMapView::invalidInputView();
		GodmodeMapView::mapOptionsView();
		break;
	}
}

void GodmodeMapController::setCell(int x, int y, Cell* cell) {
	map->fillCell(x, y, cell);
}

void GodmodeMapController::print() {
	map->print();
}

GodmodeMapController* GodmodeMapController::instance() {
	if (!s_instance)
		s_instance = new GodmodeMapController();

	return s_instance;
}

GodmodeMapController* GodmodeMapController::s_instance = GodmodeMapController::instance();