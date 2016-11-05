#pragma once
#include <iostream>;

using namespace std;

class Interactable
{
public:
	Interactable();
	Interactable(string name, string description);
	virtual void interact() = 0;

private:
	string name;
	string description;
};