#include "GodmodeItemView.h"

//! Displays the options of which item to create
void GodmodeItemView::createItem()
{
	int selection = 0;
	string name;

	do
	{
		system("cls");
		cout << "Item creation menu" << endl;
		cout << endl << "Select the type of item you would like to create" << endl;
		cout << "1. " << ItemTypes[ARMOR] << endl;
		cout << "2. " << ItemTypes[SHIELD] << endl;
		cout << "3. " << ItemTypes[WEAPON] << endl;
		cout << "4. " << ItemTypes[BOOTS] << endl;
		cout << "5. " << ItemTypes[RING] << endl;
		cout << "6. " << ItemTypes[HELMET] << endl;

		cout << "Input [1,6] : ";
		cin.clear();
		cin >> selection;
	} while (selection < 1 || selection > 6);

	cout << endl << "Input the name you would like to give your item: " << endl;
	cin >> name;

	system("cls");
	GodmodeItemController::instance()->addItem(selection, name);
}

//! Displays to user which items of type to view
void GodmodeItemView::viewItemByType()
{
	int selection = 0;
	string name;

	do
	{
		system("cls");
		cout << "Item viewer menu" << endl;
		cout << endl << "Select the type of items you would like to view" << endl;
		cout << "1. " << ItemTypes[ARMOR] << endl;
		cout << "2. " << ItemTypes[SHIELD] << endl;
		cout << "3. " << ItemTypes[WEAPON] << endl;
		cout << "4. " << ItemTypes[BOOTS] << endl;
		cout << "5. " << ItemTypes[RING] << endl;
		cout << "6. " << ItemTypes[HELMET] << endl;

		cout << "Input [1,6] : ";
		cin.clear();
		cin >> selection;
	} while (selection < 1 || selection > 6);

	GodmodeItemView::displayItemHelper(selection);
	GodmodeItemView::itemOptionSelection();
}

//! Displays all items in container
void GodmodeItemView::viewAllItems()
{
	cout << "All items: " << endl;

	for (int i = 1; i <= HELMET + 1; i++) 
	{
		GodmodeItemView::displayItemHelper(i);
	}
}

//! Displays to user which item to remove
void GodmodeItemView::removeItem()
{
	int selection, itemToDelete; 
	vector<Item*> itemsSelected;

	do
	{
		system("cls");
		GodmodeItemView::viewAllItems();

		cout << "Select the item type of the item you would like to destroy.\nNo item will be deleted if there are no items of a specific type." << endl;

		cout << "1. " << ItemTypes[ARMOR] << endl;
		cout << "2. " << ItemTypes[SHIELD] << endl;
		cout << "3. " << ItemTypes[WEAPON] << endl;
		cout << "4. " << ItemTypes[BOOTS] << endl;
		cout << "5. " << ItemTypes[RING] << endl;
		cout << "6. " << ItemTypes[HELMET] << endl;
		cout << "7. Return to Item Menu screen." << endl;

		cout << "Input [1,7] : ";
		cin.clear();
		cin >> selection;
	} while (selection < 1 || selection > 7);

	if (selection == 7) 
	{
		system("cls");
		itemOptionSelection();
	}
	else if (GodmodeItemController::instance()->getItemsOfType(selection).size() == 0)
	{
		removeItem();
	}
	else
	{
		GodmodeItemView::displayItemHelper(selection);
		itemsSelected = GodmodeItemController::instance()->getItemsOfType(selection);
		cout << "Input the number of the item you would like to delete: " << endl;
		do
		{
			cin.clear();
			cin >> itemToDelete;
		} while (itemToDelete < 1 || itemToDelete > itemsSelected.size());
		GodmodeItemController::instance()->removeItem(ItemTypes[selection -1], itemToDelete);
	}
}

//! View option to save an item inventory
void GodmodeItemView::saveItemInventory()
{
	cout << "Please enter filename: ";
	string filename;

	cin >> filename;

	GodmodeItemController::instance()->saveItemInventory(filename);
}

//! View option to load an item inventory
void GodmodeItemView::loadItemInventory(vector<string> filenames)
{
	if (filenames.size() == 0)
	{
		cout << "There are no item inventory files to load." << endl;
	}
	else
	{
		cout << "Please select one of the following files:" << endl;

		for (int i = 0; i < filenames.size(); i++) {
			cout << i + 1 << ". " << filenames[i] << endl;
		}

		int input = 0;
		do
		{
			cout << "Selection: ";
			cin >> input;
		} while (input < 1 || input > filenames.size());

		cin.clear(); //if cin fails because of wrong data type, clear error flag

		GodmodeItemController::instance()->loadItemInventory(input - 1);
	}
}

//! Displays action success
void GodmodeItemView::successfulAction()
{
	cout << "Action successfully completed." << endl; 
}

//! Displays all item of a specific type
void GodmodeItemView::displayItemHelper(int selection) 
{
	vector<Item*> itemsSelected = GodmodeItemController::instance()->getItemsOfType(selection);

	if (itemsSelected.size() == 0)
	{
		cout << endl << "No items of type: " << ItemTypes[selection - 1] <<  endl;
	}
	else
	{
		cout << endl << "Displaying all items of type: " << ItemTypes[selection - 1] << endl;
		int i = 1;
		for (vector<Item*>::iterator it = itemsSelected.begin(); it != itemsSelected.end(); ++it)
		{
			cout << "Item: " << i++ << endl;
			cout << "Item name: " << (*it)->getItemName() << endl;
		}
	}
}

//! Item menu interface
void GodmodeItemView::itemOptionSelection() {
	int input = 0;
	while (input < 1 || input > 6) {
		cout << "------------------------------" << endl
			<< "1. New item" << endl
			<< "2. View item" << endl
			<< "3. Destroy item" << endl
			<< "4. Save item container" << endl
			<< "5. Load item container" << endl
			<< "6. Return to Selection menu" << endl
			<< "------------------------------" << endl;
		cout << "Input [1,6] : ";
		cin >> input;
		system("cls");
	}
	GodmodeItemController::instance()->menuHelper(input);
}
