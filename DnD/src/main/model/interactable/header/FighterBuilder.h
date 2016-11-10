#pragma once
#include <iostream>
#include "Fighter.h"

using namespace std;

class FighterBuilder
{
public:
	FighterBuilder::FighterBuilder();
	FighterBuilder::FighterBuilder(string name, string description, int level);
	FighterBuilder::~FighterBuilder();
	Fighter* build();

	FighterBuilder* setStrength(int str);
	FighterBuilder* setDexterity(int dex);
	FighterBuilder* setConstitution(int con);
	FighterBuilder* setIntelligence(int intel);
	FighterBuilder* setWisdom(int wis);
	FighterBuilder* setCharisma(int cha);
private:
	Fighter *_fighter;
};
