/*! Chest class
* Placed in map and allow player to interact
*/
#pragma once
#include <iostream>
#include "Passive.h"

using namespace std;

class Chest : public Passive
{
public:
	Chest();
	Chest(string name, string description);
	~Chest();
	void interact();
	void open();
	void print();
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Chest);
private:
	//item
};
