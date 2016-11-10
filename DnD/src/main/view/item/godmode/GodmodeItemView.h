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
	static void equipItem();
	static void unequipItem();
private:
	static void displayItemHelper(int);
};

