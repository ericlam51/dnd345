#pragma once
#include <iostream>
#include "Interactable.h"
#include <string>

using namespace std;

class Passive : public Interactable
{
public:
	Passive();
	Passive(string name, string description);
	~Passive();
	void interact();

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Passive);
};
