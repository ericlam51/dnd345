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
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Chest);
private:
	//item
};
