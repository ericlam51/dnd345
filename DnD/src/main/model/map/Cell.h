#pragma once
#define NO_WARN_MBCS_MFC_DEPRECATION
#include "../../helper/CellHelper.cpp"
#include <afx.h>

class Cell : public CObject
{
protected:
	char type;
	int posX;
	int posY;

public:
	Cell();
	~Cell();
	virtual bool interactable();
	virtual bool walkable();
	char getType();
	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);

	virtual void Serialize(CArchive& archive);
	virtual void interact();
	DECLARE_SERIAL(Cell);
};

