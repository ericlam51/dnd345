/*! Interactable class
* Super class of Active and Passive
* Contains common attributes to all Active and Passive which is any interactable in game
*/
#pragma once

#define NO_WARN_MBCS_MFC_DEPRECATION
#include <iostream>
#include <afx.h>

using namespace std;

class Interactable : public CObject
{
public:
	Interactable();
	Interactable(string name, string description);
	~Interactable();
	string getName() const;
	string getDescription() const;

	virtual void interact();

	virtual void Serialize(CArchive& archive);
	DECLARE_SERIAL(Interactable);

protected:
	string name;
	string description;
};