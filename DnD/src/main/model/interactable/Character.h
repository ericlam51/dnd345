#pragma once
#include <iostream>;
#include "Interactable.h";

using namespace std;

class Character : public Interactable
{
public:
	Character();
	Character(string name, string description, int level);
	void interact() = 0;

private:
	string name;
	string description;
	int level;
	int hitpoints;
};
