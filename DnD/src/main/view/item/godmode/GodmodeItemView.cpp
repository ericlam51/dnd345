#include "GodmodeItemView.h"

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
}

void GodmodeItemView::viewAllItems()
{
	cout << "All items: " << endl;

	for (int i = 1; i <= HELMET + 1; i++) 
	{
		GodmodeItemView::displayItemHelper(i);
	}
}

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

void GodmodeItemView::saveItemInventory()
{
	GodmodeItemController::instance()->saveItemInventory();
}

void GodmodeItemView::loadItemInventory()
{
	GodmodeItemController::instance()->loadItemInventory();
}

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

	//TODO: Robby change
	int in;
	cin >> in;
}

void GodmodeItemView::itemOptionSelection() {
	int input = 0;
	while (input < 1 || input > 5) {
		cout << "------------------------------" << endl
			<< "1. New item" << endl
			<< "2. View item" << endl
			<< "3. Destroy item" << endl
			<< "4. Save item container" << endl
			<< "5. Load item container" << endl
			<< "------------------------------" << endl;
		cin >> input;
		system("cls");
	}
	switch (input) {
	case 1:
		createItem();
		break;
	case 2:
		viewItemByType();
		break;
	case 3:
		removeItem();
		break;
	case 4:
		saveItemInventory();
		break;
	case 5:
		loadItemInventory();
		break;
	}
}
