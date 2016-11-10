#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/FighterBuilder.h"
#include "../header/Fighter.h"
#include <string>

using namespace std;

FighterBuilder::FighterBuilder() {}
FighterBuilder::FighterBuilder(string name, string description, int level) {
	_fighter = new Fighter(name, description, level);
}

FighterBuilder::~FighterBuilder() {
	cout << "FighterBuilder deleted" << endl;
	delete _fighter;
}

FighterBuilder* FighterBuilder::setStrength(int str) {
	_fighter->setStrength(str);
	return this;
}

FighterBuilder* FighterBuilder::setDexterity(int dex) {
	_fighter->setStrength(dex);
	return this;
}

FighterBuilder* FighterBuilder::setConstitution(int con) {
	_fighter->setStrength(con);
	return this;
}

FighterBuilder* FighterBuilder::setIntelligence(int intel) {
	_fighter->setStrength(intel);
	return this;
}

FighterBuilder* FighterBuilder::setWisdom(int wis) {
	_fighter->setStrength(wis);
	return this;
}

FighterBuilder* FighterBuilder::setCharisma(int cha) {
	_fighter->setStrength(cha);
	return this;
}

Fighter* FighterBuilder::build() {
	return _fighter;
}

