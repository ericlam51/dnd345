#pragma once
#include <iostream>
#include "Passive.h"
#include <string>

using namespace std;

class FriendlyNpc : public Passive
{
public:
	FriendlyNpc();
	FriendlyNpc(string name, string description, string dialog);
	void interact();

private:
	string dialog;
};
