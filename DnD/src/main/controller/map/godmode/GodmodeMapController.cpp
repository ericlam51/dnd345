//! @file 
//! @brief Implementation file for the PlayModeController
//!

#include "GodmodeMapController.h"
#include "../../interactable/godmode/GodmodeChestController.h"
#include "../../interactable/godmode/GodmodeActiveController.h"
#include "../../../model/interactable/header/Fighter.h"
#include "../../../helper/FileHelper.h"

//! Controller to receive request from GodmodeMapView::fileOptionsMenuView()
//! @param input: user input
void GodmodeMapController::mapFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapCreationInputView();
		break;
	case 2:
		s_instance->getSavedMapFiles();
		//s_instance->loadMap();
		break;
	case 3:
		//GameModeView::displayView(3);
		break;
	default: 
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::fileOptionsMenuView();
		break;
	}
}

//! Controller to receive request to create a new map
//! @param height: height of map
//! @param width: width of map
void GodmodeMapController::newMap(int width, int height) {
	if (width == 0 || height == 0) {
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::mapCreationInputView();
	}
	else {
		if (map != NULL)
			delete map;

		map = new Map(width, height);
		map->print();
		GodmodeMapView::mapOptionsMenuView();
	}
}

//! Controller to receive request to change a cell from the map
//! @param y: y position of the cell
//! @param x: x position of the Cell
//! param charType: type of Cell. For all possible types, see CellHelper object.
void GodmodeMapController::fillCell(int x, int y, char charType) {
	if (x < 0 || x > map->getWidth() || y < 0 || y > map->getHeight()) {
		GodmodeMapView::warningMsgWrongCoordinates();
		GodmodeMapView::mapFillOptionsMenuView();
		return;
	}

	if (charType == NULL) {
		GodmodeMapView::warningMsgWrongCellType();
		GodmodeMapView::mapFillOptionsMenuView();
		return;
	}

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

//! Controller to receive request to edit the map in some ways
//! @param input: user input
void GodmodeMapController::mapOptions(int input) {
	switch (input) {
	case 1:
		GodmodeMapView::mapFillOptionsMenuView();
		break;
	case 2:
		GodmodeMapController::instance()->validateMap();
		break; 
	case 3:
		GodmodeMapController::instance()->validateSaveRequirements();
		//GodmodeMapController::instance()->saveMap();
		break;
	case 4:
		//GameModeView::displayView(3);
		break;
	default:
		GodmodeMapView::warningMsgInvalidInput();
		GodmodeMapView::mapOptionsMenuView();
		break;
	}
}

//! Controller to receive request to save the map
void GodmodeMapController::saveMap(string filename) {
	CFile theFile;
	string fileDirectory = FileHelper::getDirectoryPath(FileHelper::MAP_FILE_FOLDER) + filename;
	theFile.Open(_T(fileDirectory.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	map->Serialize(archive);

	archive.Close();
	theFile.Close();

	GodmodeMapView::warningMsgMapSaved();
	GodmodeMapView::mapOptionsMenuView();
}

void GodmodeMapController::validateSaveRequirements() {
	bool valid = map->validateMap();

	if (!valid) {
		GodmodeMapView::warningMsgInvalidMap();
		GodmodeMapView::mapOptionsMenuView();
		return;
	}

	GodmodeMapView::mapAskSaveFileName();
}

//! Controller to receive request to validate the map
void GodmodeMapController::validateMap() {
	bool valid = map->validateMap();

	if (valid)
		GodmodeMapView::warningMsgValidMap();
	else
		GodmodeMapView::warningMsgInvalidMap();

	GodmodeMapView::mapOptionsMenuView();
}

//! Method called by fillCell, which is turn called by the view. 
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

//! Controller to receive request to print the map
void GodmodeMapController::print() {
	map->print();
}

//! Controller to receive request to load map
void GodmodeMapController::loadMap(int input) {
	if (input < 0 || input >= filenames.size()) {
		GodmodeMapView::mapChooseSaveMapFileView(filenames);
	} else {
		CFile theFile;
		string filePath = FileHelper::getDirectoryPath(FileHelper::MAP_FILE_FOLDER) + filenames[input];
		theFile.Open(_T(filePath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		map = new Map();
		map->Serialize(archive);

		archive.Close();
		theFile.Close();

		print();
		GodmodeMapView::warningMsgMapLoaded();
		GodmodeMapView::mapOptionsMenuView();
	}
}

void GodmodeMapController::getSavedMapFiles() {
	filenames = FileHelper::getFilenamesInDirectory(FileHelper::MAP_FILE_FOLDER);

	GodmodeMapView::mapChooseSaveMapFileView(filenames);
}

GodmodeMapController* GodmodeMapController::instance() {
	if (!s_instance)
		s_instance = new GodmodeMapController();

	return s_instance;
}

void GodmodeMapController::resetController() {
	delete map;
	map = NULL;

	filenames.clear();
	vector<string>().swap(filenames);
}

GodmodeMapController* GodmodeMapController::s_instance = GodmodeMapController::instance();