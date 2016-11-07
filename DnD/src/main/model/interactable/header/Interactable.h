#pragma once
#include <iostream>
#include "../../../helper/Location.h"

using namespace std;

class Interactable
{
public:
	Interactable();
	Interactable(string name, string description, Location location);
	int getXCoordinate();
	int getYCoordinate();
	virtual void interact() = 0;

protected:
	string name;
	string description;
	Location location;
};