#pragma once
#include <iostream>;
#include "NonPlayerCharacter.h";

using namespace std;

class FriendlyNpc : public NonPlayerCharacter
{
public:
	FriendlyNpc();
	FriendlyNpc(string name, string description, int level, int range);
	void interact() = 0;

private:
	int range;
};
