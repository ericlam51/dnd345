#include "GodmodeMapController.h"
#include "../../interactable/godmode/GodmodeChestController.h"
#include "../../interactable/godmode/GodmodeActiveController.h"
#include "../../../model/interactable/header/Fighter.h"

void GodmodeMapController::mapFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapCreationInputView();
		break;
	case 2:
		s_instance->loadMap();
		break;
	default: 
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::fileOptionsMenuView();
		break;
	}
}

void GodmodeMapController::newMap(int width, int height) {
	if (width == 0 || height == 0) {
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::mapCreationInputView();
	}
	else {
		map = new Map(width, height);
		map->print();
		GodmodeMapView::mapOptionsMenuView();
	}
}

void GodmodeMapController::fillCell(int x, int y, char charType) {
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
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::mapFillOptionsMenuView();
		break;
	}
}

void GodmodeMapController::mapOptions(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapFillOptionsMenuView();
		break;
	case 2:
		GodmodeMapController::instance()->validateMap();
		break; 
	case 3:
		GodmodeMapController::instance()->saveMap();
		break;
	default:
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::mapOptionsMenuView();
		break;
	}
}

void GodmodeMapController::saveMap() {
	bool valid = map->validateMap();

	if (!valid) {
		GodmodeMapView::warningMsgInvalidMap();
		GodmodeMapView::mapOptionsMenuView();
		return;
	}

	CFile theFile;
	theFile.Open(_T("Map.txt"), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	map->Serialize(archive);

	archive.Close();
	theFile.Close();

	GodmodeMapView::warningMsgMapSaved();
	GodmodeMapView::mapOptionsMenuView();
}

void GodmodeMapController::validateMap() {
	bool valid = map->validateMap();

	if (valid)
		GodmodeMapView::warningMsgValidMap();
	else
		GodmodeMapView::warningMsgInvalidMap();

	GodmodeMapView::mapOptionsMenuView();
}

void GodmodeMapController::setCell(int x, int y, Cell* cell) {
	map->fillCell(x, y, cell);
	map->print();
	
	switch (cell->getType()) {
		//case CellHelper::WALL_TYPE:
		//	//dynamic_cast<WallCell*>(cell)->set
		//	break;
		//case  CellHelper::ENTRANCE_TYPE:
		//	s_instance->setCell(x, y, new EntranceCell());
		//	break;
		//case  CellHelper::EXIT_TYPE:
		//	s_instance->setCell(x, y, new ExitCell());
		//	break;
	case  CellHelper::CHEST_TYPE:
	{
		GodmodeChestController::instance()->loadChestWithoutView();
		Interactable* chest = GodmodeChestController::instance()->getChest();
		dynamic_cast<ChestCell*>(cell)->setChest(chest);
		break;
	}
	case  CellHelper::ENTITY_TYPE:
	{
		GodmodeActiveController::instance()->loadHostileNpcWithoutView();
		Interactable* entity = GodmodeActiveController::instance()->getActive();
		dynamic_cast<EntityCell*>(cell)->setEntity(entity);
		break;
	}
	}
	//case  CellHelper::PATH_TYPE:
	//	s_instance->setCell(x, y, new PathCell());
	//	break;
	//}

	GodmodeMapView::mapOptionsMenuView();
}

void GodmodeMapController::print() {
	map->print();
}

void GodmodeMapController::loadMap() {
	CFile theFile;
	theFile.Open(_T("Map.txt"), CFile::modeRead);
	CArchive archive(&theFile, CArchive::load);

	map = new Map();
	map->Serialize(archive);

	archive.Close();
	theFile.Close();

	print();
	GodmodeMapView::warningMsgMapLoaded();
	GodmodeMapView::mapOptionsMenuView();
}

GodmodeMapController* GodmodeMapController::instance() {
	if (!s_instance)
		s_instance = new GodmodeMapController();

	return s_instance;
}

GodmodeMapController* GodmodeMapController::s_instance = GodmodeMapController::instance();