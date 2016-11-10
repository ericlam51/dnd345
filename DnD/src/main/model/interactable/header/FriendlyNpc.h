/*! HostileNpc class
* NPC class, sub class of Passive send dialog to player
*/

#pragma once
#include <iostream>
#include "Passive.h"
#include <string>

using namespace std;

class FriendlyNpc : public Passive
{
public:
	FriendlyNpc();
	FriendlyNpc(string name, string description, string dialog);
	~FriendlyNpc();
	void print();
	void interact();

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(FriendlyNpc);
private:
	string dialog;
};