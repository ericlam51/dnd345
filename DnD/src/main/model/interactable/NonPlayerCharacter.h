#pragma once
#include <iostream>;
#include "Character.h";

using namespace std;

class NonPlayerCharacter : public Character
{
public:
	NonPlayerCharacter();
	NonPlayerCharacter(string name, string description, int level, int range);
	void interact() = 0;

private:
	int range;
};
