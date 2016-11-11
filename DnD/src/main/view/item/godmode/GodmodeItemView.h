#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include "../../../controller/item/godmode/GodmodeItemController.h"

using namespace std;

class GodmodeItemView
{
public:
	static void createItem();
	static void viewItemByType();
	static void viewAllItems();
	static void removeItem();
	static void itemOptionSelection();
	static void saveItemInventory();
	static void loadItemInventory();
private:
	static void displayItemHelper(int);
};

