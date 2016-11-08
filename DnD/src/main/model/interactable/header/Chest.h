#pragma once
#include <iostream>
#include "Passive.h"

using namespace std;

class Chest : public Passive
{
public:
	Chest();
	Chest(string name, string description, Location location);
	void interact();
	void open();

private:
	//item
};
