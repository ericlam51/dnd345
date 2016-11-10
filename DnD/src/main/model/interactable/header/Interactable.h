#pragma once
#define NO_WARN_MBCS_MFC_DEPRECATION
#include <iostream>
#include "../../Location.h"
#include <afx.h>

using namespace std;

class Interactable : public CObject
{
public:
	Interactable();
	Interactable(string name, string description);
	~Interactable();
	void setLocation(Location location);
	string getName() const;
	string getDescription() const;
	Location getLocation() const;

	virtual void interact();

	virtual void Serialize(CArchive& archive);
	DECLARE_SERIAL(Interactable);

protected:
	string name;
	string description;
	Location location;
};