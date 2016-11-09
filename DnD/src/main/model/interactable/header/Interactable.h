#pragma once
#include <iostream>
#include "../../Location.h"

using namespace std;

class Interactable
{
public:
	Interactable();
	Interactable(string name, string description);
	void setLocation(Location location);
	string getName() const;
	string getDescription() const;
	Location getLocation() const;
	virtual void interact() = 0;

protected:
	string name;
	string description;
	Location location;
};