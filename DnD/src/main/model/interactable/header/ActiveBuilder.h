#pragma once
#include <iostream>
#include "Active.h"

using namespace std;

class ActiveBuilder
{
public:
	ActiveBuilder();
	ActiveBuilder(string name, string description, int level, int type);
	~ActiveBuilder();
	Active* build();

	ActiveBuilder* setStrength(int str);
	ActiveBuilder* setDexterity(int dex);
	ActiveBuilder* setConstitution(int con);
	ActiveBuilder* setIntelligence(int intel);
	ActiveBuilder* setWisdom(int wis);
	ActiveBuilder* setCharisma(int cha);
private:
	Active *_activeObj;
	int type;
};
