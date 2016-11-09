#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/ActiveBuilder.h"
#include "../header/Fighter.h"
#include "../header/HostileNpc.h"
#include <string>

using namespace std;

ActiveBuilder::ActiveBuilder() {}

ActiveBuilder::ActiveBuilder(string name, string description, int level, int type) : type(type) {
	if(type == 0)
		_activeObj = new Fighter(name, description, level);
	else
		_activeObj = new HostileNpc(name, description, level);
}

ActiveBuilder::~ActiveBuilder() {
	cout << "FighterBuilder deleted" << endl;
	delete _activeObj;
}

ActiveBuilder* ActiveBuilder::setStrength(int str) {
	_activeObj->setStrength(str);
	return this;
}

ActiveBuilder* ActiveBuilder::setDexterity(int dex) {
	_activeObj->setStrength(dex);
	return this;
}

ActiveBuilder* ActiveBuilder::setConstitution(int con) {
	_activeObj->setStrength(con);
	return this;
}

ActiveBuilder* ActiveBuilder::setIntelligence(int intel) {
	_activeObj->setStrength(intel);
	return this;
}

ActiveBuilder* ActiveBuilder::setWisdom(int wis) {
	_activeObj->setStrength(wis);
	return this;
}

ActiveBuilder* ActiveBuilder::setCharisma(int cha) {
	_activeObj->setStrength(cha);
	return this;
}

Active* ActiveBuilder::build() {
	return _activeObj;	
}

