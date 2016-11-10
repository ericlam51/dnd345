#pragma once

#include <iostream>
#include "Active.h"

using namespace std;

class HostileNpc : public Active
{
public:

	HostileNpc();
	HostileNpc(string name, string description, int level);
	~HostileNpc();
	void interact();

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(HostileNpc);

private:
	int size;
};