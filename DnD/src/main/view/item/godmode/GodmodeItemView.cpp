#include "GodmodeItemView.h"

//! Displays the options of which item to create
void GodmodeItemView::createItem()
{
	int selection = 0;
	string name;

	cout << "Item creation menu" << endl;
	cout << endl << "Select the type of item you would like to create" << endl;
	cout << "1. " << ItemTypes[ARMOR] << endl;
	cout << "2. " << ItemTypes[SHIELD] << endl;
	cout << "3. " << ItemTypes[WEAPON] << endl;
	cout << "4. " << ItemTypes[BOOTS] << endl;
	cout << "5. " << ItemTypes[RING] << endl;
	cout << "6. " << ItemTypes[HELMET] << endl;

	do
	{
		cin.clear();
		cin >> selection;
	} while (selection < 1 || selection > 6);

	cout << endl << "Input the name you would like to give your item: " << endl;
	cin >> name;

	GodmodeItemController::instance()->addItem(selection, name);
}

//! Displays to user which items of type to view
void GodmodeItemView::viewItemByType()
{
	int selection = 0;
	string name;

	cout << "Item viewer menu" << endl;
	cout << endl << "Select the type of items you would like to view" << endl;
	cout << "1. " << ItemTypes[ARMOR] << endl;
	cout << "2. " << ItemTypes[SHIELD] << endl;
	cout << "3. " << ItemTypes[WEAPON] << endl;
	cout << "4. " << ItemTypes[BOOTS] << endl;
	cout << "5. " << ItemTypes[RING] << endl;
	cout << "6. " << ItemTypes[HELMET] << endl;

	do
	{
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

	GodmodeItemView::viewAllItems();
	vector<Item*> itemsSelected;

	cout << "Select the item type of the item you would like to destroy." << endl;
	cout << "1. " << ItemTypes[ARMOR] << endl;
	cout << "2. " << ItemTypes[SHIELD] << endl;
	cout << "3. " << ItemTypes[WEAPON] << endl;
	cout << "4. " << ItemTypes[BOOTS] << endl;
	cout << "5. " << ItemTypes[RING] << endl;
	cout << "6. " << ItemTypes[HELMET] << endl;

	do
	{
		cin.clear();
		cin >> selection;
	} while (selection < 1 || selection > 6);

	if (GodmodeItemController::instance()->getItemsOfType(selection).size() == 0)
	{
		cout << "There are no items of this type to remove." << endl;
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
	GodmodeItemController::instance()->saveItemInventory();
}

//! View option to load an item inventory
void GodmodeItemView::loadItemInventory()
{
	GodmodeItemController::instance()->loadItemInventory();
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
		cin >> input;
		system("cls");
	}
	GodmodeItemController::instance()->menuHelper(input);
}
