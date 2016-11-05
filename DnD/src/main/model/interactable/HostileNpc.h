#pragma once
#include <iostream>;
#include "NonPlayerCharacter.h";

using namespace std;

class HostileNpc : public NonPlayerCharacter
{
public:
	enum SizeEnum
	{
		Small, Medium, Large
	};

	HostileNpc();
	HostileNpc(string name, string description, int level, int range, int size, int attack, int damage, int armorClass);
	void interact() = 0;

private:
	int range;
	int size;
	int attack;
	int damage;
	int armorClass;
};
