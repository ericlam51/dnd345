#pragma once
#include <iostream>
#include "Interactable.h"

using namespace std;

class Chest : public Interactable
{
public:
	Chest();
	Chest(string name, string description, Location location);
	void interact() = 0;
};
