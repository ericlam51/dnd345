#pragma once
#include <iostream>
#include "Interactable.h"

using namespace std;

class Character : public Interactable
{
public:
	Character();
	Character(string name, string description, Location location, int level);
	string getName() const;
	string getDescription() const;
	Location getLocation() const;
	int getLevel() const;
	void interact() = 0;

private:
	int level;
	int hitpoints;
};
