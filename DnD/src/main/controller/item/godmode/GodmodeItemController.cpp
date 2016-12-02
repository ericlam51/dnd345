#include "GodmodeItemController.h"


//! default constructor that initializes an item container
GodmodeItemController::GodmodeItemController() 
{
	container = new ItemContainer();
}

//! singleton instantiation method
GodmodeItemController* GodmodeItemController::instance() {
	if (!s_instance)
		s_instance = new GodmodeItemController();

	return s_instance;
}

//! method that handles user input to add an item to the item container
//! @param selection: the user input of which type of item to create
//! @param name: the name of the item
void GodmodeItemController::addItem(int selection, string name)
{
	Item* item;
	switch (selection) 
	{
		case 1:
			item = new Armor(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 2:
			item = new Shield(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 3:
			item = new Weapon(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 4:
			item = new Boots(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 5:
			item = new Ring(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 6:
			item = new Helmet(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
	}
	GodmodeItemView::successfulAction();
	GodmodeItemView::itemOptionSelection();

}

void GodmodeItemController::menuHelper(int input)
{
	switch (input) {
	case 1:
		GodmodeItemView::createItem();
		break;
	case 2:
		GodmodeItemView::viewItemByType();
		break;
	case 3:
		GodmodeItemView::removeItem();
		break;
	case 4:
		GodmodeItemView::saveItemInventory();
		break;
	case 5:
		GodmodeItemView::loadItemInventory(FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER));
		break;
	case 6:
		//GameModeView::displayView(3);
		break;
	}
}

string GodmodeItemController::getLoadedFile()
{
	if (FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER).size() > 0)
	{
		return FileHelper::getDirectoryPath(FileHelper::ITEM_CONTAINER_FILE_FOLDER) + FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER)[loadedFile];
	}
	return "";
}

void GodmodeItemController::setLoadedFile(int file)
{
	loadedFile = file;
}

void GodmodeItemController::resetController()
{
	delete container;
	container = NULL;
	delete s_instance;
	s_instance = NULL;
}

//! method that handles user input to remove an item from the item container
//! @param type: the object type to be deleted
//! @param index: the index of the item to be deleted inside the vector 
void GodmodeItemController::removeItem(string type, int index)
{
	Item* item = container->getItem(type, index - 1);
	container->removeItem(item);
	GodmodeItemView::successfulAction();
	GodmodeItemView::itemOptionSelection();
}

//! method that returns a vector of the specific item type
//! @param selection: a user input that is mapped to a item type
//! @return the vector of the specified type
vector<Item*> GodmodeItemController::getItemsOfType(int selection)
{
	return GodmodeItemController::instance()->container->getItemsOfType(ItemTypes[selection - 1]);
}

//! method that serializes the item inventory
void GodmodeItemController::saveItemInventory(string filename)
{
	CFile theFile;
	string fileDirectory = FileHelper::getDirectoryPath(FileHelper::ITEM_CONTAINER_FILE_FOLDER) + filename;
	theFile.Open(_T(fileDirectory.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&theFile, CArchive::store);

	container->Serialize(archive);

	archive.Close();
	theFile.Close();

	GodmodeItemView::successfulAction();
	GodmodeItemView::itemOptionSelection();
}

//! method that loads a serialized item inventory
void GodmodeItemController::loadItemInventory(int input, bool skip)
{
	setLoadedFile(input);
	string filePath = FileHelper::getDirectoryPath(FileHelper::ITEM_CONTAINER_FILE_FOLDER) + FileHelper::getFilenamesInDirectory(FileHelper::ITEM_CONTAINER_FILE_FOLDER)[input];
	loadSaveFile(filePath);

	GodmodeItemView::successfulAction();
	if (!skip) 
	{
		GodmodeItemView::itemOptionSelection();	
	}
}

void GodmodeItemController::loadSaveFile(string filepath) {
	if (filepath.length() > 0)
	{
		CFile theFile;
		theFile.Open(_T(filepath.c_str()), CFile::modeRead);
		CArchive archive(&theFile, CArchive::load);

		ItemContainer* cont = new ItemContainer();
		cont->Serialize(archive);

		container = cont;

		archive.Close();
		theFile.Close();
	}
}

ItemContainer* GodmodeItemController::getContainer() {
	return container;
}

GodmodeItemController* GodmodeItemController::s_instance = GodmodeItemController::instance();
