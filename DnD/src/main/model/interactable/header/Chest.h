#pragma once
#include <iostream>
#include "Passive.h"

using namespace std;

class Chest : public Passive
{
public:
	Chest();
	Chest(string name, string description);
	void interact();
	void open();

private:
	//item
};
