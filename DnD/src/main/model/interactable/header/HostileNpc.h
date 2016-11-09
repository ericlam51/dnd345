#pragma once

#include <iostream>
#include "Active.h"

using namespace std;

class HostileNpc : public Active
{
public:

	HostileNpc();
	HostileNpc(string name, string description, int level);
	void interact();

private:
	int size;
};
