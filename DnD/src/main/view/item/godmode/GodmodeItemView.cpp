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

void GodmodeItemView::viewItems()
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

	vector<Item*> itemsSelected = GodmodeItemController::instance()->getItemsOfType(selection);

	if (itemsSelected.size() == 0) 
	{
		cout << "No items of that type" << endl;
	}
	else
	{
		cout << "Displaying all items of type: " << ItemTypes[selection - 1] << endl;
		for (vector<Item*>::iterator it = itemsSelected.begin(); it != itemsSelected.end(); ++it) 
		{
			cout << "Item name: " << (*it)->getItemName() << endl;
		}
	}
}
